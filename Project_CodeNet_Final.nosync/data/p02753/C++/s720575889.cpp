#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string st;
	cin >> st;
    int f = 0;
    if(st.at(0) != st.at(1)) f = 1;
    if(st.at(2) != st.at(1)) f = 1;
    if(st.at(0) != st.at(2)) f = 1;
    if(f == 1){
	  cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
}