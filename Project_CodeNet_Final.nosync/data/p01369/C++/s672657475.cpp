#include<iostream>
using namespace std;
bool check(char x){
    char a[12]="yuiophjklnm";
    for(int i=0;i<11;i++)if(a[i]==x)return true;
    return false;
}
int main(){
    string s;
    while(cin>>s,s!="#"){
        bool now = check(s[0]);
        int ans = 0;
        for(int i=1;i<s.size();i++){
            if(check(s[i]) != now)ans++,now = 1 - now;
        }
        cout<<ans<<endl;
    }
    return 0;
}