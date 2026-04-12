#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
 string str; cin >> str;
 bool pos=false;
 for(int i=0;i<str.size()-1;i++){
   if(str[i]=='A' && str[i+1]=='C'){
     pos=true;
     break;
   }
 }
 if(pos) cout << "Yes" << endl;
 else cout << "No" << endl;
}