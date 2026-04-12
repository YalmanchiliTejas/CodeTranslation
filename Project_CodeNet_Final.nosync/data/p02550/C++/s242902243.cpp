#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int x, m ,n;
    cin>>n>>x>>m;
    long long int ans=x%m;
    long long int no=x%m;
    if(n<=m){
        for(int i=1; i<n; i++)
        {
            no=(no*no)%m;
            ans+=no;
        }
    }
    else
    {
        long long int prefixsum[100002]={0};
        unordered_map<long long int, long long int> map;
        map[no]=1;
        prefixsum[0]=0;
        prefixsum[1]=no;
        for(long int i=1; i<n; i++){
            no=(no*no)%m;
            if(map[no]>0){
                long long int length=i+1-map[no];
                ans=prefixsum[map[no]-1];
                // cout<<n/length<<" "<<prefixsum[map[no]+n%length]<<" "<<prefixsum[map[no]-1]<<endl       ;
                ans=ans+(n-map[no])/length*(prefixsum[i]-prefixsum[map[no]-1])+(prefixsum[map[no]+(n-map[no])%length]-prefixsum[map[no]-1]);
                break;
            }
            else
            {
                prefixsum[i+1]=prefixsum[i]+no;
                map[no]=i+1;
            }
            // cout<<no<<" ";
        }
    }
    cout<<ans;
}
