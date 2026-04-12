#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

const long long int INF=99999999999999,inf=199999;
const long long int mod=1000000007;

long long int n,dp[200000]={},a[200000],mymax=1;
string str[2000];


int main() {
    int count=0;
    map<long long int,long long int>mp;
	cout << fixed << setprecision(10);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[n]=a[1];
    for(int i=1;i<=n-1;i++){
        dp[i]=INF;
    }
    dp[n+1]=INF;
    for(int i=2;i<=n;i++){
        long long int ng=n-mymax,ok=n+1,mid;
        while(ok-ng>1){
            mid=(ok+ng)/2;
            if(dp[mid]<a[i]){
                ng=mid;
            }else{
                ok=mid;
            }
            //cout<<i<<" "<<ok<<" "<<ng<<endl;;
        }
        if(ng==n-mymax){
            //cout<<i;
            dp[n-mymax]=a[i];
            mymax++;
            
        }else{
            dp[ng]=a[i];
        }

    }
    cout<<mymax;
} 
