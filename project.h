
struct GroupElement {
  mpz_t x;
} G;

G mul(G x,unsigned long int y);

G add(G x,int y);

G inv(G x,int y);

int order();

G generator();
