#include <iostream>
#include <iomanip> //setprecision()
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
using ll = long long;
using namespace std;

double Mcos(double k){return cos(k*atan(1.0)*4/180);}

void monmo(){
    
}

int main() {
    ll n,x,m;
    cin>>n>>x>>m;
    map<long,int> map;
    long tmp=x;
    long sum=0;
    long sum1=0;
    long sum2=0;
    int flag=0;
    long tmp2;
    long i;
    for(i=1;i<=n;i++){
        map[tmp]++;
        if(map[tmp]==2){
            flag=1;
            tmp2=tmp;
            break;
        }
        sum1+=tmp;
        tmp=(long)pow(tmp,2)%m;
    }
    if(flag==0){
        cout<<sum1;
        exit(0);
    }
    long l;
    tmp=x;
    for(l=1;l<=i;l++){
        map[tmp]++;
        if(map[tmp]==3){
            break;
        }
        sum2+=tmp;
        tmp=(long)pow(tmp,2)%m;
    }
    long sum3=sum1-sum2;
    long tw = (n-l+1)/(i-l);
    long tp = (n-l+1)%(i-l);
    sum=sum2+sum3*tw;
    for(int i=0;i<tp;i++){
        sum+=tmp2;
        tmp2=(long)pow(tmp2,2)%m;
    }
    cout<<sum;
}
