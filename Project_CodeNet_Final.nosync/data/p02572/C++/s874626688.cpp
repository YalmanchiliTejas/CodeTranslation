#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    const long long int mod=1e9+7;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    unsigned long long int suffix_sum=0;
    unsigned long long int result=0;
    unsigned long long int answer=0;
    for(int j=n-1;j>=0;j--){

        answer=v[j];
        suffix_sum%=mod;
        answer*=suffix_sum;
        suffix_sum+=v[j];
        answer%=mod;
        result+=answer;
    }
    cout<<result%mod;
}