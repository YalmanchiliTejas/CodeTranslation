#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define all(v) (v).begin(),(v).end()
#define clr(t,v) memset(t,(v),sizeof(t))
template<class T1, class T2>ostream& operator<<(ostream& os, const pair<T1, T2>&a)
{
   return os << "(" << a.first << "," << a.second << ")";
}
template<class T>void pv(T a, T b)
{
   for(T i = a; i != b; ++i)
      cout << (*i) << " ";
   cout << endl;
}
template<class T>void chmin(T&a, const T&b)
{
   if(a > b)
      a = b;
}
template<class T>void chmax(T&a, const T&b)
{
   if(a < b)
      a = b;
}

int nxint()
{
   int x;
   scanf("%d", &x);
   return x;
}

int a[200005], b[200005];
int main()
{
   int m, n;
   while(cin >> n) {
      rep(i, n){
      cin >> a[i];
      b[i] = a[i];
      }
      sort(a, a + n);
      rep(i, n){
         if(b[i] < a[n / 2])
            cout << a[n / 2] << endl;
         else
            cout << a[n / 2 - 1] << endl;

      }


   }

   return 0;
}
