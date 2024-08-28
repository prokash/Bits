#include "stdio.h"

/*
 *EVEN PARITY => #0 BITS == #1 BITS
 */
#include "stdlib.h"

//#include "string.h"
#include "stdbool.h"
int  bit_write(int x, int bit_value, int bit_pos) {
    unsigned  mask = 1 << bit_pos;
    if (bit_value)
        x = x | mask;
    else
        x = x & (~mask);
    return (x);
}
int swap_bits(int x, int pos1, int pos2) {

    //int bit1, bit2;
    printf("before x=%d\n", x);

    printf("(x >> pos1) & 1 =%d\n", (x >> pos1) & 1);
    int bit1 =  (x >> pos1) & 1;

    printf("(x >> pos2) & 1 =%d\n", (x >> pos2) & 1);
    int bit2 = (x >> pos2) & 1;

    if (bit1 != bit2) {
        x = bit_write(x, bit2, pos1);
        x = bit_write(x, bit1, pos2);
    }
    printf("after x=%d\n", x);
}

//AI genned this when I start x = x & . Its optimal
unsigned optimal_bit_counts (unsigned x) {
    unsigned counts = 0;
    while (x) {
        x = x & (x - 1);
        ++counts;
    }
    return counts;
}
//-- AI genned- O(n) not optimal, but for a start good enough
unsigned count_bit(unsigned x) {
    unsigned count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}
void parity (unsigned N) {
    unsigned i;
    unsigned count = 0;
    for (i = 1; i <= N; i++) {
        if ((i % 2) == 0) {
            printf("even %d\n", i);
            count -= 1;
        } else {
            printf("odd %d\n", i);
            count += 1;
        }
    }
    printf("\nparity= %d\n\n", count);
}

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

void bit_test_quick() {
    //quick test
    int x = -1;
    printf("X=");
    print_binary(x);
    printf("\n");

    printf("y=");
    unsigned y = x;
    print_binary(y);
    printf("\n");

    printf("\nx = %d\n", x);
    printf("y = %ul\n", y);

    print_binary(y>>1);
    printf("\n");
    print_binary(x>>1);
    printf("\n");

    printf("\nx>>1 = %d\n", x>>1);
    printf("y >>1= %u\n", y>>1);
}
void bit_tests (unsigned N ) {
    // bit_test_quick();
    print_binary(N);

}

void parity_test() {
    parity(10);
    parity(11);
}

void swap_bits_test() {
    printf("Testing swap_bits\n");

    swap_bits(10,1,2);

}

void reverse_bit ( unsigned int N) {
    printf("Testing reverrse_bit N=0x%x\n", N);
    print_binary(N); printf("\n");
    unsigned int x = 0;
    unsigned  Nb_of_Bits = sizeof (N) * 8;
    for (int i = 0; i < Nb_of_Bits; i++) {
        if ( (N & (1<<i) ) )
            x |= 1 << ((Nb_of_Bits - 1) - i);
    }
    printf("x=0x%x\n", x);
    print_binary(x);
}
void reverse_bit_uchar( unsigned char  N) {
    printf("Testing reverrse_bit N=0x%x\n", N);
    print_binary(N); printf("\n");
    unsigned char   x = 0;
    unsigned  Nb_of_Bits = sizeof (N) * 8;
    for (int i = 0; i < Nb_of_Bits; i++) {
        if ( (N & (1<<i) ) )
            x |= 1 << ((Nb_of_Bits - 1) - i);
    }
    printf("x=0x%x\n", x);
    print_binary(x);
}


int main(void) {
    printf("Hello, World!\n");

   // OK parity_test();
   // bit_tests(2);
   // printf("\n");
   // bit_tests(3);
   // OK swap_bits_test();
   // reverse_bit(2);
    reverse_bit_uchar(4);
    return 0;
}
