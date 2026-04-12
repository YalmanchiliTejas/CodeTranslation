#include <bits/stdc++.h>
using namespace std;
 


 
int main() {


    int n;
    cin>>n;

    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }

    int64_t sum=0;
    int64_t sum1=0;
    for(int i=n-2;i>=0;i--){
        sum1+=(a.at(i+1));
        sum+=((sum1%(1000000007))*a.at(i))%(1000000007);
        sum%=1000000007;
    }

    cout<<sum<<endl;

 	return 0;
}