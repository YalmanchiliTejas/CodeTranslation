#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main(void){
    // Your code here!
    vector<string> YN{"NO","YES"};
    vector<string> yn{"No","Yes"};
    int a,b,c;
    cin>>a>>b>>c;
    cout<<YN[(b*10+c)%4==0]<<endl;
    
}
