#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
 string s;
 cin >> s;

 if(s.at(0)==s.at(1)&&s.at(1)==s.at(2)&&s.at(2)==s.at(0))
{cout << "No"<<endl;}
else
{
    cout << "Yes" <<endl;
}


    return 0;
}