#include<bits/stdc++.h>
using namespace std;

void boost1() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {

    long long int n,x,m,i,j,prev,ans,finalans,curr,flag=INT_MIN,rem;
    cin>>n>>x>>m;
    prev=x;
    finalans=x;
    unordered_map<long long int,long long int>mp;
    mp[x]=1;
    for(i=2;i<=n;i++)
    {
        ans=(prev*prev)%m;
        // cout<<ans<<" ";
        if(mp[ans]!=0)
        {
            long long int prev_pos=mp[ans];
            long long int cycle_length=i-prev_pos;
            long long int done_uptill=i-1;
            long long int rem_cnt=n-done_uptill;
            long long int cnt=rem_cnt/cycle_length;
            vector<long long int>cycle;
            vector<long long int>pre_sum;
            for(j=prev_pos;j<i;j++)
            {
                long long int val=ans;
                cycle.push_back(val);
                ans=(ans*ans)%m;
            }
            long long int pree=0;
            for(j=0;j<cycle.size();j++)
            {
                pree+=cycle[j];
                pre_sum.push_back(pree);
            }
            finalans+=(cnt*pre_sum[cycle_length-1]);
            long long int remm=rem_cnt%cycle_length;
            if(remm!=0)
                finalans+=pre_sum[remm-1];
            break;
        }
        if(ans==0)
        {
            flag=0;
            break;
        }
        if(ans==1)
        {
            flag=1;
            curr=i;
            break;
        }
        finalans=finalans+ans;
        prev=ans;
        mp[ans]=i;
    }
    // cout<<"aaya"<<endl;
    // cout<<endl;
    if(flag==0)
    {
        cout<<finalans<<endl;
    }
    else if(flag==1)
    {
        prev=finalans;
        rem=n-curr+1;
        finalans=finalans+rem;
        cout<<finalans<<endl;
    }
    else{
        cout<<finalans<<endl;
    }

    
}
