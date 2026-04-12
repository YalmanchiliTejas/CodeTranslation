#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        vector<int> s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        sort(s.begin(),s.end());
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans+=s[i];
        }
        cout<<ans/(n-2)<<endl;
    }
    return 0;
}

