#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    string s,dv="11111110000000001111011101";//left->1,right->0
    while(true){
        cin>>s;
        if(s=="#") break;
        char last=dv[s[0]-'a'];
        int res=0;
        for(int i=1;i<(int)s.length();i++){
            if(dv[s[i]-'a']!=last){
                res++;
                last =dv[s[i]-'a'];
            }
        }
        cout<<res<<endl;
    }
}