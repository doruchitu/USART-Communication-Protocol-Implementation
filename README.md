# USART-Communication-Protocol-Implementation

Descriere:

Acest proiect implementează un protocol de comunicație USART (Universal Synchronous Asynchronous Receiver Transmitter) pe un microcontroler, utilizând limbajul de programare C/C++. Scopul acestui proiect este de a demonstra modul în care pot fi gestionate transmisiunile și recepțiile de date între două dispozitive prin intermediul portului serial, folosind microcontrolere.

Proiectul include:

Configurarea transmisiei și recepției de date prin USART.
Controlul unui LED prin comenzi seriale ("LED ON" / "LED OFF").
Răspuns automatizat care trimite înapoi mesajul primit de la utilizator.

Funcționalități:

Transmiterea și recepționarea datelor:

Proiectul permite trimiterea și primirea de caractere prin portul serial USART.
Se folosește un microcontroler pentru a trimite și a recepționa date între două dispozitive conectate.

Controlul LED-ului:

Comenzile primite prin USART sunt folosite pentru a controla un LED conectat la un pin al microcontrolerului.
Comenzile acceptate sunt: „LED ON” și „LED OFF”.

Răspuns la mesaje:

Sistemul răspunde înapoi cu un mesaj de tipul: „You said: [mesajul primit]”.

Tehnologii utilizate:

C/C++ pentru programarea microcontrolerului.
USART pentru comunicarea serială.
Microcontrolere (ATmega).
LED control prin portul digital al microcontrolerului.
Instrucțiuni de utilizare

Configurarea hardware-ului:

Conectează microcontrolerul la un PC printr-un adaptor USB-serial (dacă nu este deja integrat).
Asigură-te că LED-ul este conectat corect la pinul specificat în cod (de exemplu, PORTB).
Setează portul serial pe 9600 bauds.
Compilare și încărcare:

Compilează proiectul folosind un IDE de dezvoltare pentru microcontrolere (ex. Atmel Studio, PlatformIO, Arduino IDE).
Încarcă codul pe microcontroler.
Comunicare serială:

Folosește un terminal serial pentru a trimite mesaje către microcontroler prin portul serial.
Testează comenzi ca „LED ON” și „LED OFF” pentru a controla LED-ul.
