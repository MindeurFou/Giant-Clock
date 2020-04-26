# Giant-Clock
 Simple electronic project I have made for fun

 It's based on an Arduino NANO and a time module : DS1307RTC.

 I used some led strips to create big size 7 segments display. I wired them with common cathode and each anode is wired to a pin of an ULN2803A.

 To avoid using a huge number of pins, I used a multiplexing technique : wired all A segments together, B segments together and so on... I used bipolar transistors to control which display is on. Please check on the schematic for clearer explanations.
