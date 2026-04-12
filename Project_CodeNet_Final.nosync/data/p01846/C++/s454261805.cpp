#include <iostream>
#include <vector>
using namespace std;

int main(){
    string S;
    while(cin>>S,S!="#"){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector<string> V;
        V.push_back("");
        for(auto s:S){
            if(s=='b'){
                V.back()+='b';
            }else if(s=='/'){
                V.push_back("");
            }else{
                V.back()+=string(s-'0','.');
            }
        }
        V[a-1][b-1]='.'; V[c-1][d-1]='b';
        string ans;
        for(auto v:V){
            int cnt = 0;
            for(int c:v){
                if(c=='b'){
                    if(cnt){
                        ans+='0'+cnt;
                        cnt=0;
                    }
                    ans+='b';
                }else{
                    cnt++;
                }
            }
            if(cnt){
                ans+='0'+cnt;
                cnt=0;
            }
            ans+='/';
        }
        ans.pop_back();
        cout<<ans<<endl;
    }

    return 0;
}