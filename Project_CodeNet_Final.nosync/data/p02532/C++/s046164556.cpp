#include<iostream>
#include<stack>
using namespace std;

int main(){
string s;
char c;
stack<char> st[110];
int n,p;
cin >> n;

while(cin >> s, s!="quit"){
if(s=="pop"){
cin >> n;
if(st[n].empty())continue;
cout << st[n].top() << endl;
st[n].pop();
}else if(s=="push"){
cin >> n >> c;
st[n].push(c);
}else{
cin >> n >> p;
st[p].push(st[n].top());
st[n].pop();
}
}
}