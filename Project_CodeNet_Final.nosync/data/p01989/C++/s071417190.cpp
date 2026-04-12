#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >>s;
    int ans = 0;
    for(int i = 1; i < s.size();i++ ){
        for(int j = 1; j+i < s.size();j ++){
            for (int k =  1; k+j+i < s.size();k ++){
                string a = s.substr(0,i);
                string b = s.substr(i,j);
                string c = s.substr(j+i,k);
                string d = s.substr(k+j+i);
                if(a.size() and b.size() and c.size() and d.size()){
                    if(stoi(a) <=255 and stoi(b) <= 255 and stoi(c) <= 255 and stoi(d) <= 255){
                       if((a.size()> 1  and a.front() == '0') or (b.size()>1 and b.front() == '0') or (c.size() > 1 and c.front() == '0')
                          or (d.size() > 1 and d.front() == '0'))
                           continue;
                      else   ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}



