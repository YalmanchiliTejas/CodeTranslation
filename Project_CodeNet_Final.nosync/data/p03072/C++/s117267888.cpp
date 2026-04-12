#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m=0;
    int c=1;
    bool b;
    unordered_map<unsigned, unsigned> un_mp;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> m;
        un_mp[i]=m;
    }
    for(int i=n; i>1; --i){
        b=true;
        if(un_mp[i]<un_mp[i-1]){
            continue;
        }else{
            for(int j=(i-1); j>=1; --j){
                if(un_mp[i]<un_mp[j]){
                    b=false;
                    continue;
                }
            }
        }
        if(b==true){
            c+=1;
        }
    }
    cout << c << endl;
}