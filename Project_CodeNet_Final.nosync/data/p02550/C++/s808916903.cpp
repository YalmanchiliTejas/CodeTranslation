#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll int n,x,m,i,j;
    ll p,ans,result;
    ll c,f=INT_MIN,r;
    
    cin>>n>>x>>m;
    p=x;
    result=x;
    unordered_map<ll,ll>mp;
    
    mp[x]=1;
    
    for(i=2;i<=n;i++)
    {
        ans=(p*p)%m;
        if(mp[ans]!=0)
        {
            ll pp=mp[ans];
            ll cl=i-pp;
            ll du=i-1;
            ll rc=n-du;
            ll w=rc/cl;
            
            vector<ll>array;
            vector<ll>ps;
            
            for(j=pp;j<i;j++)
            {
                ll v=ans;
                array.push_back(v);
                ans=(ans*ans)%m;
            }
            
            ll pre=0;
            
            for(j=0;j<array.size();j++)
            {
                pre+=array[j];
                ps.push_back(pre);
            }
            
            result+=(w*ps[cl-1]);
            ll rm=rc%cl;
            if(rm!=0)
                result+=ps[rm-1];
            break;
        }
        if(ans==0)
        {
            f=0;
            break;
        }
        if(ans==1)
        {
            f=1;
            c=i;
            break;
        }
        result+=ans;
        p=ans;
        mp[ans]=i;
    }
    if(f==0)
    {
        cout<<result<<endl;
    }
    else if(f==1)
    {
        p=result;
        r=n-c+1;
        result+=r;
        cout<<result<<endl;
    }
    else{
        cout<<result<<endl;
    }

    
}