#define FOSC 16e6 // 16MHz
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

class UART {
 public: 
  void init() {
    int ubrr = MYUBRR;
    
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
UCSR0B = (1<<RXEN0) | (1<<TXEN0);
DDRD |= 0b00000010; // iesire pt Tx 1
DDRD &= 0b11111110; // intrare pt Rx 0
UCSR0C = (0<<USBS0) | (3<<UCSZ00);
  }

bool available() {
    return (UCSR0A & (1<<RXC0));
  }


void writeByte(const char& d) {
    while (!(UCSR0A & (1<<UDRE0)));
    UDR0 = d;
  }

  char readByte() {
while (!(UCSR0A & (1<<RXC0)));
return UDR0;

  }
void writeString(const char* msg) {
    for (int i = 0; i < strlen(msg); i++)
      writeByte(msg[i]);
  }
};

UART uart;

void setup() {
  uart.init();
  DDRB |= 0b00000010;
  TCCR1A = (1 << COM1A1) | (1<< COM1A0 | (1 << WGM11));
  TCCR1B = (1 << WGM13) | (1 << WGM12)|(1 << CS12) | (1<<CS10);

  DDRD = DDRD & ~(1<<6);
  DDRB |= 0b0000001;

  ICR1 = 10938;
  OCR1A = 7813;
}

bool inline readBtnState() {
if (PIND & 0b01000000)
return true;
return false;
}

void responseBack(const char* userMsg) {
  uart.writeString("You said: ");
  uart.writeString(userMsg);
}

char buf[1024];
int index = 0;

void loop() {
  
if (uart.available()){
  buf[index] = uart.readByte();
  index++;
  }
  
 if(buf[index-1] == '\n') {
  buf[index] = 0;
  responseBack(buf);
  index=0;
  }

if(strcmp(buf,"LED ON")==0){
   PORTB |= 0b0000001;
   uart.writeString("Led ON\n");
  }
 else if(strcmp(buf, "LED OFF") == 0){
  PORTB &= ~0b0000001;
  uart.writeString("Led OFF\n");
  }
}
