#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int cnt;
    string s;
    bool judge;
    map <char,bool> j;
    j['a']=j['q']=j['z']=j['w']=j['s']=j['x']=j['e']=j['c']=j['d']=j['r']=j['f']=j['v']=j['t']=j['g']=j['b'] = true;
    j['u']=j['j']=j['m']=j['y']=j['h']=j['n']=j['i']=j['k']=j['o']=j['l']=j['p'] = false;
    while(1){
        cnt = 0;
        cin >> s;
        if(s[0] == '#') break;
        judge = j[s[0]];
        for(int i=1;i<s.size();i++){
            if(judge != j[s[i]]){
                cnt++;
                judge = j[s[i]];
            }
        }
        cout << cnt << endl;
    }
}