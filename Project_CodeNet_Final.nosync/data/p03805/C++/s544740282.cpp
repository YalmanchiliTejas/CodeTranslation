#include "bits/stdc++.h"
using namespace std;

#define ul unsigned long long
#define ll long long

int main()
{
  int gra[8][8];
  fill(gra[0],gra[0]+64,0);
  size_t n,m,ca,cb;
  cin>>n>>m;
  for (size_t i = 0; i < m; i++)
  {
    cin>>ca>>cb;
    ca--,cb--;
    gra[ca][cb] = 1;
    gra[cb][ca] = 1;
  }

  size_t pat[8]={0,1,2,3,4,5,6,7};
  ul ct=0;
  do {
    ul cj=1;
    for (size_t i = 1; i < n; i++)
    {
      if (!gra[pat[i-1]][pat[i]]) {
        cj=0;
        break;
      }
    }
    ct+=cj;
  } while (next_permutation(&pat[1],pat+n));

  cout<<ct<<endl;

  return 0;
}
