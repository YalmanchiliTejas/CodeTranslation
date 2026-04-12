#include <iostream>
#include <vector>

using namespace std;

vector <char> ALPHABET(26); 

int main(){
  int n;
  cin >> n;
//init APLPHABET
  for(int i = 0; i < 26; i++){
    ALPHABET[i] = char('a' + i);
  }
  
  vector<string> S(n);
  for(int i = 0; i < n; i++) cin >> S[i];
  
  vector<int> isect(26,51);
  for(int a = 0; a < isect.size(); a++){
    for(int i = 0; i < n; i++){
      int l = S[i].size();
      int t = 0;
      for(int j = 0; j < l; j++){
        if(S[i][j] == ALPHABET[a]){
          t++;
        }
      }
      if(isect[a] > t) isect[a] = t;
    }
  }
  string ans;
  
  for(int i = 0; i < isect.size(); i++){
    int t = isect[i];
    while(t > 0){
    ans.push_back(ALPHABET[i]);
    t--;
    }
  }
  cout << ans;
}
