#include <bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f  
typedef long long ll;  
const int N = 310;  
#define FI first
#define SE second
typedef pair<int, int>pii;

char num[N];
bool vis[N];
int main()  
{  
 
 
   // ios::sync_with_stdio(0);
   int a , b, c;
   while (cin >> a >> b >> c)
   {
     a*= 10;
     a += b;
     a *= 10;
     a += c;
     printf("%s\n", a%4 == 0?"YES":"NO");
   }
   return 0;  

}  