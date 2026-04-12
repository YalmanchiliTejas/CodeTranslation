#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
int main(){
    int h,w,cnt =0;cin >>h >>w;
    char p;
    while(cin>>p){
        if(p=='#'){
            ++cnt;
        }
    }
    if(cnt==h+w-1){
        cout << "Possible";
    }
    else{
        cout << "Impossible";
    }
}
