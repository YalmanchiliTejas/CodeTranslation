#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int main(){

  stack <string> a[10000];
  int n;
  string s;

  cin >> n;

  while(1){

    cin >> s;
    if(s == "quit") break;

    else if(s == "pop"){
      cin >> n;
      cout << a[n].top() << endl;
      a[n].pop();
    }

    else if(s == "move"){
      cin >> n;
      s = a[n].top();
      a[n].pop();

      cin >> n;
      a[n].push(s);
    }

    else{
      cin >> n >> s;
      a[n].push(s);
    }
  }
}