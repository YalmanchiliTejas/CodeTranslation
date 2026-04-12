#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<math.h>
#define pi 3.141592653589
#include<iomanip>
using namespace std;
#include<algorithm>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define Max(a,b) max(a,b)
#define Min(a,b) min(a,b)
#define INF 1e9
#define LINF 1e17
#define ll long long
#define MOD (int)(1e9+7)

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};



int main(){
    
    int a,b,c;
    
    cin>>a>>b>>c;
    if((10*b+c)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
        
    return 0;
}