
#define clrBit_M(Register, BitPos) (Register &= ~(1 << BitPos))
#define setBit_M(Register, BitPos) (Register |= (1 << BitPos))
#define checkBit_M(Register, BitPos) (Register & (1 << BitPos))

#define bSwap(x, y)  { (x) ^= (y); (y) ^= (x); (x) ^= (y);}

#define nSwap(x, y)  {y = x; x &= 0x0F; y &= 0xF0; x << 4; y >> 4; x |= y;}

#define nSplit(byte, low, high); \
	high = byte & 0xF0;\
	low = byte & 0x0F;\
	high >>= 4;
