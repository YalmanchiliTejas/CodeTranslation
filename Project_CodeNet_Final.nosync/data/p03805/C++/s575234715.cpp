#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m; cin>>n>>m;
    vector <bool> data(89,false);
    vector <int> nums(n,0);
    for(int i=0;i<n;i++){
        nums[i]+=1+i;
       // cout<<nums[i]<<endl;
    }
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        data[a*10+b]=true;
        data[a+10*b]=true;
    }
    int count=0;
    do{
        
        if(nums[0]==1){
            bool ok=true;
        for(int i=0;i<n-1;i++){
            if(data[nums[i]*10+nums[i+1]]==false) ok=false;
        }
        if(ok) count++;
        }
    }while(next_permutation(nums.begin(),nums.end()));
    cout<<count<<endl;
}