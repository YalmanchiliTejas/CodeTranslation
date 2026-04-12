#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k;
    string s,output;
    cin >> n;
    cin >> s;
    cin >> k;

    for(int i = 0;i < n;i++){
        if(s[i] == s[k-1])output += s[i];
        else output += "*";
    }
  
  	cout << output << endl;

    return 0;
}