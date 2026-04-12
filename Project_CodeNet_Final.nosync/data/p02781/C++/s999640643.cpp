#include <iostream>
#include <vector>
#include <cmath>
#include <map>

typedef long long int ll;

using namespace std;
string N;
int K;

ll e(string strN, int k)
{
  int i,j;
  int top;
  int second=0, si=0;
  int third=0, ti=0;
  int keta;
  ll ret = 0;

  top = strN[0] - '0';
  keta = strN.length();
  if (keta<k) return 0;
  for (i=1; i<keta; i++) {
    if (strN[i]-'0'>0) {
      second = strN[i] - '0';
      si = keta-i;
      i++;
      break;
    }
  }
  for (; i<keta; i++) {
    if (strN[i]-'0'>0) {
      third = strN[i] - '0';
      ti = keta-i;
      break;
    }
  }

//printf("top=%d, keta=%d, second=%d, si=%d, third=%d, ti=%d\n", top, keta, second, si, third, ti);

  switch(k) {
  case 1:
    ret = 9LL*(keta-1)+top;
    break;
  case 2:
    ret = (ll)9*9*(keta-1)*(keta-2)/2;  //keta-1���܂ł̕��� (keta-1C2)*9*9
    ret += (ll)(top-1)*9*(keta-1);      //�ŏ�ʌ��̍ő�l-1��keta-1�܂ł̑g�ݍ��킹
    if (second) {
      ret += (ll)9*(si-1)+second;       //�ŏ�ʌ��̍ő�l��si�܂ł̑g�ݍ��킹
    }
    break;
  case 3:
    ret = (ll)9*9*9*(keta-1)*(keta-2)*(keta-3)/6;  //keta-1���܂ł̕��� (keta-1C3)*9*9*9
    ret += (ll)(top-1)*9*9*(keta-1)*(keta-2)/2;    //�ŏ�ʌ��̍ő�l-1��keta-1�܂ł̑g�ݍ��킹
    if (second) {
      ret += (ll)9*9*(si-1)*(si-2)/2;
      ret += (ll)(second-1)*9*(si-1);              //2�Ԗڂ̌��̍ő�l-1��si�܂ł̑g�ݍ��킹
    }
    if (third)
      ret += (ll)9*(ti-1)+third;                   //2�Ԗڂ̌��̍ő�l��ti�܂ł̑g�ݍ��킹
    break;
  }

  return ret;
}

bool ncount(int j, int n) {
  int nc=0;
  while(j>0) {
    if (j%10) nc++;
    if (nc>n) return false;
    j/=10;
  }
  return nc==K;
}
int ho() {
  int n=stoi(N);
  int ret=0;

  for (int i=1; i<=n; i++) {
    if (ncount(i, n)) {
//      printf("%d\n", i);
      ret++;
    }
  }
  return ret;
}

main() {

  cin >> N;
  cin >> K;

  printf("%lld\n", e(N, K));
  return 0;
}
