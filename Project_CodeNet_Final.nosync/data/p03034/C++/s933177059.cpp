// KALAM
# include<bits/stdc++.h>

using namespace std;

const int N = 101000 + 577 , SQ = 517 , TB = 202;
long long S[N][SQ] , res;
int n , a[N];
vector < int > D[N];

inline long long Calc(int x , int y , int td) {
   if(y < SQ)
      return S[x][y] - S[min(N - 1 , x + td * y)][y];
   long long rr = 0;
   while((td --) > 0 && x < n)
      rr += a[x] , x += y;
   return rr;
}
int main() {
   for(int i = 1;i < N;++ i)
      for(int j = i;j < N;j += i)
         D[j].push_back(i);
   scanf("%d" , & n);
   for(int i = 0;i < n;++ i)
      scanf("%d" , a + i);
   for(int i = n - 1;i >= 0;-- i)
      for(int j = 1;j < SQ;++ j)
         S[i][j] = S[i + j][j] + a[i];
   for(int A = 2;A < n - 1;++ A) {
      for(int x : D[n - A - 1]) {
         int na = A;
         int ndiff = x;
         int nb = A - ndiff;
         if(nb <= 0 || (na % ndiff == 0 && na + nb < n - 1))
            continue ;
         int tx = (n - 1 - na) / ndiff;

         res = max(res , Calc(na , ndiff , tx) + Calc(ndiff , ndiff , tx));//+ Calc(0 , ndiff));
      }

   }
   printf("%lld\n" , res);
   return 0;
}
