#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

string S;
char F[10][10];

int main(){
    while(cin >> S && S!="#"){
        int a,b,c,d;
        vector<string> v;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        string T = "";
        int h = 0;
        for(int i=0;i<S.size();i++){
            if(S[i]!='/') T += S[i];
            if(S[i]=='/' || i==S.size()-1){
                v.push_back(T);
                T = "";
                h++;
            }
        }
        assert(v.size()==h);
        int w = 0;
        for(int i=0;i<v.size();i++){
            int a = 0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]=='b'){
                    F[i][a] = '#';
                    a++;
                }else{
                    int n = v[i][j]-'0';
                    for(int k=a;k<a+n;k++) F[i][k] = '.';
                    a += n;
                }
            }
            w = a;
        }
        F[a][b] = '.'; F[c][d] = '#';
        vector<string> ans;
        for(int i=0;i<h;i++){
            string now = "";
            int num = 0;
            for(int j=0;j<w;j++){
                if(F[i][j]=='#'){
                    char c = '0'+num;
                    if(num!=0) now += c;
                    now += 'b';
                    num = 0;
                }else num++;
            }
            if(num!=0){
                char c = '0'+num;
                now += c;
            }
            ans.push_back(now);
        }
        for(int i=0;i<ans.size();i++) cout << ans[i] << (i!=ans.size()-1? "/":"\n");
    }
}
