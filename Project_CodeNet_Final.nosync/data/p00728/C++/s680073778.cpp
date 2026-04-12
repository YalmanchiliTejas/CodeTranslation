#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main(){
        int n;
        while(cin>>n&&n){
                ll ans=0;
                vector<int>s(n);
                for(int i=0;i<n;i++){
                        cin>>s[i];
                        ans+=s[i];
                }
                sort(s.begin(),s.end());
                ans=ans-s[0]-s[n-1];
                cout<<ans/(n-2)<<endl;
        }
        return 0;
}

