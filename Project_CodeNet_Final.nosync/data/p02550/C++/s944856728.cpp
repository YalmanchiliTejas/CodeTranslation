#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    unsigned long long int n,x,m,i,j,k,y,z,sum,pref=0,a;
    vector<unsigned long long int>vt;
    map<long long int,long long int>mt;
    vt.push_back(0);
    cin>>n>>x>>m;
    vt.push_back(x);
    mt[x]=1;
    sum=x;
    for(i=2;i<=n;i++){
        x*=x;
        y=x%m;
        if(mt[y]==1){
            k=1;
            pref=y;
            for(j=i-1;j>=1;j--){
                if(vt[j]==y)
                    break;
                 pref+=vt[j];
                 k+=1;
            }
          //  cout<<k<<" "<<pref<<endl;
            sum+=((n-i+1)/k)*pref;
            k=(n-i+1)%k;
            for(a=j;a<j+k;a++){
                sum+=vt[a];
            }
            break;
        }
        //cout<<y<<endl;
        mt[y]=1;
        vt.push_back(y);
        sum+=y;
        x=vt.back();

    }
    cout<<sum;
    return 0;
}
