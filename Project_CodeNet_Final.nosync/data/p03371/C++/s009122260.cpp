#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main()
{
    int A,B,C,X,Y;
    cin >> A>>B>>C>>X>>Y;
    
    int sum_min=1<<30;
    for (int i = 0; i <= max(X,Y); i++){
        int a = X-i;
        int b = Y-i;
        int c = i*2;
        a = max(0,a);
        b = max(0,b);
        int sum = a*A+b*B+c*C;
        //printf("i=%d a:%d b:%d c:%d sum:%d\n", i, a,b,c,sum);
        if(sum_min>sum) sum_min=sum;
      	//cout<<sum_min<<endl;
    }
    cout << sum_min << endl;   

    return 0;
}