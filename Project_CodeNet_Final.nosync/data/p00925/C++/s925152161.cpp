#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define im imag()
#define re real()
#define r(I, N) for(int I=0;I<N;I++)
#define f(I, A, B) for(int I=A;I<B;I++)
#define fd(I, A, B) for(int I=A;I>=B;I--)
#define ite(x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define sz(x) ((int)(x).size())
#define clr(x) memset(x, 0, sizeof(x))

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ld> Point;
typedef Point Vector;

const ld pi = acos(-1.0);
const ld eps = 1e-12;

int l1, l2;
char s[123];
ll num[123], ans;
bool f1 = true, f2 = true;
string buf;

void parse(string u)
{
      int pt;
      r(i, u.length())
      {
            if(u[i] >= '0' && u[i] <= '9')
            {

                  pt = i;
                  while(u[pt] >= '0' && u[pt] <= '9' && pt < u.length())
                  {
                        pt++;
                  }
                  ll tmp = 0;
                  f(j, i, pt) tmp *= 10, tmp += u[j] - '0';
                  num[l2++] = tmp;i = pt - 1;
            }
            else
            {
                  s[l1++] = u[i];
            }
      }
}


int main()
{
      cin >> buf >> ans;
      parse(buf);
      /// lr Case 1
      ll a1 = num[0];
      r(i, l1)
      {
            if(s[i] == '+')
            {
                  a1 += num[i + 1];
            }
            else
            {
                  a1 *= num[i + 1];
            }
      }
      if(a1 != ans) f1 = false;

      /// mf Case 2
      ll a2 = num[0];
      ll t = 0;
      r(i, l1)
      {
            if(s[i] == '*')
            {
                  a2 *= num[i + 1];
            }
            else
            {
                  t += a2;
                  a2 = num[i + 1];
            }
      }
      t += a2;
      if(t != ans) f2 = false;
      if(f1 && f2) cout << "U" << endl;
      else if(f1 && !f2) cout << "L" << endl;
      else if(!f1 && f2) cout << "M" << endl;
      else cout << "I" << endl;
      return 0;
}