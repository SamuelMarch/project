#include "project.h"

#include <gmp.h>
#include <stdio.h>
#include <math.h>

// Things to do:

// Tested with hard coded ElGamal implementation in main()

// Need a initialise / set function(s) in the header

// Generator should return a random element
// Functions shouldn't have to calculate p every time
// p,q should be global variables

// query over passing structs or pointers to structs and G.x -> G->x

// need a makefile to link gmp etc.

// meeting with D. Bernhard to discuss next steps e.g. Nacl / Tweet Nacl.

// Returns x^y (mod p)
// Uses gmp library for now for fast square and multiply etc.
G mul(G x,unsigned long int y){
    // new member to be returned containing answer
    mpz_t z;
    mpz_init(z);

    // member containing p, move clearly
    mpz_t p;
    mpz_init(p);
    mpz_set_ui(p,100103);

    // actual calculation
    mpz_powm_ui(z,G.x,y,p);
    return z;
}

// Returns x*y (mod p) where * is group operation
// Uses gmp library for now for fast square and multiply etc.
G add(G x,G y){
    mpz_t p;
    mpz_init(p);
    mpz_set_ui(p,100103);

    mpz_t z;
    mpz_init(z);

    mpz_mul(z,G.x,G.y);
    mpz_mod(z,p);
    return z;
}
// Returns x^q-1 (mod p) s.t. x * x^q-1 (mod p) = 1 (mod p)
// Uses gmp library for now for fast square and multiply etc.
G inv(G x,int y){
  // new member to be returned containing answer
  mpz_t z;
  mpz_init(z);

  // member containing p, move clearly
  mpz_t p;
  mpz_init(p);
  mpz_set_ui(p,100103);

  // actual calculation
  // Raises x to q-1=500501 - 1
  mpz_powm_ui(z,G.x,500500,p);
  return z;
}

// returns order of group
// in this case order is q = 500501;
int order(){
  return 500501;
}

// returns a ~random generator of the group to be used for encyption
// for now just returns group element g = 3
G generator(){
  // new member to be returned containing answer
  mpz_t z;
  mpz_init(z);
  mpz_set_ui(z,3);
  return z;
}



int main(){
  return 0;
}
