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



int main() {
    const long long int mod = 1000000007,INF=99999999999999;
	map<long long int, long long int>mp;
    string str[2005],tmp;
	cout << fixed << setprecision(10);
    bool f[505][505] = {};
    
    while(1){
        long long int n,l,r,a[105],res=0;
        cin>>n>>l>>r;
        if(n==0){return 0;}
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        a[n]=1;
        for(int i=l;i<=r;i++){
            for(int j=0;j<=n;j++){
                if(i%a[j]==0&&j%2==0){
                    res++;
                    break;
                }else if(i%a[j]==0){
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
} 

