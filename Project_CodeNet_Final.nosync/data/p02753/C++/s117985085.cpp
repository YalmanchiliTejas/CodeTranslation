#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
string s;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> s;
    bool good = false;
    for(int i = 0; i < s.length(); i++){
      for(int j = 0; j < s.length(); j++){
        if(i!=j){
          if(s[i] != s[j]){
            good = true;
          }
        }
      }
    }
    if(good){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }



    cout.flush();
    return 0;
}