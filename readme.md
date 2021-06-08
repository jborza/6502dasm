## 6502 disassembler

### Features

- disassembling flat binaries

### Build instructions:

```sh
make
```

### Building the web version:

Requirements: 
- Install `emscripten`: https://emscripten.org/docs/getting_started/index.html

```sh
make web
```

### Usage:
```sh
./6502dasm < web/sample/07.bin
```

### Sample output:

```gas
   0:		A2 00   	LDX #$00
   2:		A0 00   	LDY #$00
   4:		8A      	TXA
   5:		99 00 02	STA $0200,Y
   8:		48      	PHA
   9:		E8      	INX
   A:		C8      	INY
   B:		99 00 02	STA $0200,Y
   E:		C8      	INY
   F:		48      	PHA
  10:		C0 20   	CPY #$20
  12:		D0 F0   	BNE $0004
  14:		68      	PLA
  15:		99 00 02	STA $0200,Y
  18:		C8      	INY
  19:		C0 40   	CPY #$40
  1B:		D0 F7   	BNE $0014
```

### TODO
- generate labels from jump instructions