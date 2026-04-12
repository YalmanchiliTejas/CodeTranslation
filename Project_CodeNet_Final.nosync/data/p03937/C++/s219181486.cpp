#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    int sum = 0;
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        for(int j=0;j<w;j++){
            if(s[j] == '#') ++sum;
        }
    }
    if(sum == h+w-1){
        cout<<"Possible\n";
    }else{
        cout<<"Impossible\n";
    }
    return 0;
}


