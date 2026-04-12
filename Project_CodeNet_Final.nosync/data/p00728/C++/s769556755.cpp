#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    while(cin>>n){
        if(n==0)return 0;
        vector<int> v(n,0);
        for(int &e:v){
            cin>>e;
        }
        sort(v.begin(),v.end());
        cout<<accumulate(v.begin()+1,v.end()-1,0)/(n-2)<<endl;
    }
    return 0;
}
