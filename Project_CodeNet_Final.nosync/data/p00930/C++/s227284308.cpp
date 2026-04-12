#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

uint64_t ary[5000]__attribute__((aligned(32)));
int diff[5000]__attribute__((aligned(32)));
int inf[5000]__attribute__((aligned(32)));
int l1,l2,n;

int _mm_popcnt_u64(uint64_t x) {
  return __builtin_popcountll(x);
}

void update(int i) {
  if (i != l1) {
    diff[i] = 2 * _mm_popcnt_u64(ary[i]) - 64;
    int cnt = 0;
    inf[i] = 0;
    REP(j,64) {
      cnt += ((ary[i] >> j) & 1) ? 1 : -1;
      inf[i] = min(inf[i], cnt);
    }
  } else {
    diff[l1] = 2 * _mm_popcnt_u64(ary[l1]) - (n % 64);
    int cnt = 0;
    inf[l1] = 0;
    REP(j,n % 64) {
      cnt += ((ary[l1] >> j) & 1) ? 1 : -1;
      inf[l1] = min(inf[l1], cnt);
    }
  }
}

int main() {
  int q;
  cin>>n>>q;
  string s;
  cin>>s;
  REP(i,n){
    if(s[i]=='(')
      ary[i/64] |= UINT64_C(1) << (i % 64);
  }
  l1 = n/64;
  l2 = (n+63)/64;
  REP(i,l1){
    diff[i] = 2 * _mm_popcnt_u64(ary[i]) - 64;
  }
  if (l1 != l2) diff[l1] = 2 * _mm_popcnt_u64(ary[l1]) - (n % 64);
  REP(i,l1) {
    int cnt = 0;
    REP(j,64) {
      cnt += ((ary[i] >> j) & 1) ? 1 : -1;
      inf[i] = min(inf[i], cnt);
    }
  }
  if (l1 != l2) {
    int cnt = 0;
    REP(j,n % 64) {
      cnt += ((ary[l1] >> j) & 1) ? 1 : -1;
      inf[l1] = min(inf[l1], cnt);
    }
  }
  REP(cnt1,q){
    int p;
    cin>>p;
    --p;
    if ((ary[p/64] >> (p % 64)) & 1) {
      ary[p/64] ^= UINT64_C(1) << (p % 64);
      update(p/64);
      int pos = -1;
      REP(j,l1) {
        if (diff[j] != 64) {
          pos = j * 64;
          REP(k,64) {
            if (!((ary[j] >> k) & 1)) {
              pos += k;
              break;
            }
          }
          break;
        }
      }
      if (pos < 0) {
        pos = l1 * 64;
        REP(j,n%64) {
          if (!((ary[l1] >> j) & 1)) {
            pos += j;
            break;
          }
        }
      }
      cout << pos+1 << endl;
      ary[pos/64] ^= UINT64_C(1) << (pos % 64);
      update(pos/64);
    } else {
      ary[p/64] ^= UINT64_C(1) << (p % 64);
      update(p/64);
      int last1 = 0;
      int last1sum = 0;
      int sum = 0;
      REP(i,l1) {
        if (sum + inf[i] <= 1) {
          last1 = i;
          last1sum = sum;
        }
        sum += diff[i];
      }
      if (l1 != l2) {
        if (sum + inf[l1] <= 1) {
          last1 = l1;
          last1sum = sum;
        }
      }
      int pos = 0;
      if (last1 != l1) {
        int last1_s = 0;
        REP(i,64) {
          last1sum += ((ary[last1] >> i) & 1) ? 1 : -1;
          if (last1sum <= 1) last1_s = i;
        }
        pos = last1 * 64 + last1_s + 1;
      } else {
        int last1_s = 0;
        REP(i,n%64) {
          last1sum += ((ary[last1] >> i) & 1) ? 1 : -1;
          if (last1sum <= 1) last1_s = i;
        }
        pos = last1 * 64 + last1_s + 1;
      }
      cout << pos+1 << endl;
      ary[pos/64] ^= UINT64_C(1) << (pos % 64);
      update(pos/64);
    }
  }
  return 0;
}