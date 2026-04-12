#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
  int n;
  string c;
  char s;
  cin >> n;
  stack<char> v[n+1];
  int a,a2;
  char k;
  while(cin>>c){
    if(c=="quit") break;
    else if(c=="push"){
      cin >> a >> s;
      v[a].push(s);
    }
    else if(c=="pop"){
      cin >> a;
      cout << v[a].top() << endl;
      v[a].pop();
    }
    else if(c=="move"){
      cin >> a >> a2;
      v[a2].push(v[a].top());
      v[a].pop();
    }
  }
    return 0;
}