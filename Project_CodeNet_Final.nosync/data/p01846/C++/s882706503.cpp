#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(){
  string s;
  while(cin >> s && s[0] != '#'){
    vector< vector< char > > non_jfen;
    vector<char> v;
    non_jfen.push_back(v);
    int hgt = 0;
    for(int i = 0 ; i < s.size(); i++){
      if(s[i] == '/'){
        non_jfen.push_back(v);
        hgt++;
      }
      else if(s[i] == 'b'){
        non_jfen[hgt].push_back(s[i]);
      }
      else{
        for(int j = 0; j < stoi(s.substr(i,1)); j++){
          non_jfen[hgt].push_back('.');
        }
      }
    }
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    non_jfen[a-1][b-1] = '.';
    non_jfen[c-1][d-1] = 'b';
    string ans;
    for(int i = 0; i < non_jfen.size(); i++){
      for(int j = 0; j < non_jfen[i].size(); j++){
        if(non_jfen[i][j] == '.'){
          a = 0;
          int k;
          for( k = j ; k < non_jfen[i].size(); k++){
            if(non_jfen[i][k] == '.') a++;
            else{
              break;
            }
          }
          j = k-1;
          ostringstream ss;
          ss << a;
          ans = ans + ss.str();
        }
        else ans.push_back('b');
      }
      if(i != non_jfen.size() - 1) ans.push_back('/');
    }

    cout << ans << endl;
  }
}

