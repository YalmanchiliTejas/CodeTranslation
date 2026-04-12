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

long long int mod=1000000007;


long long int n,k,pownum,q,a[60]={},id,res=0,memo,key=0,mypow[66]={1};
queue<pair<long long ,long long > >que;
int main() {
    const long long int INF=99999999999999;
	map<long long int, long long int>mp;
    string str[550],red[550],blue[550];
    priority_queue<long long int>pq[4];
    priority_queue<long long int>tmp[4];
	cout << fixed << setprecision(10);
    cin>>n;
    for(long long int i=1;mypow[i-1]<10000000000001000;i++){
        mypow[i]=mypow[i-1]*n;
        pownum=i;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
        key=1;
        for(int i=1;i<=n;i++){
            
            if(a[i]/n!=0){
                id=i;
                res+=a[i]/n;
                key=0;
                memo=a[i]/n;
                for(int j=1;j<=n;j++){
                    if(id==j){
                        a[j]=a[id]%n;
                    }else{
                        a[j]+=memo;
                    }
                    //cout<<a[j]<<" ";
                }
                //cout<<endl;
            }
        }
        if(key==1){break;}
    }
    cout<<res;
} 
