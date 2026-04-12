#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N,K;
    string str;
    cin >> N >> str >> K;

    for(int i = 0;i < str.size();i++){
      if(str.substr(K - 1,1) != str.substr(i,1))str.replace(i, 1, "*");
    }
    cout << str << endl;
}