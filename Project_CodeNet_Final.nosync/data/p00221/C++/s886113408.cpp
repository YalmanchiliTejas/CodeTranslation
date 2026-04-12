#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,n;
  cin >>m>>n;
  while(m!=0){
    int now=0;
    string s[n+1];
    for(int i=1;i<=n;i++){
      cin >> s[i];
    }
    list<int> l;
    for(int i=1;i<=m;i++){
      l.push_back(i);
    }

    for(int i=1;i<=n;i++){
      if((i%3==0)&&(i%5==0)){
        if(s[i]!="FizzBuzz"){
          now++;
          l.pop_front();
        }else{
          l.push_back(l.front());
          l.pop_front();
        }
      }else if(i%3==0){
        if(s[i]!="Fizz"){
          now++;
          l.pop_front();
        }else{
          l.push_back(l.front());
          l.pop_front();
        }
      }else if(i%5==0){
        if(s[i]!="Buzz"){
          now++;
          l.pop_front();
        }else{
          l.push_back(l.front());
          l.pop_front();
        }
      }else{
        stringstream ss;
        string s2;
        ss <<i;
        ss >>s2;
        if(s[i]!=s2){
          now++;
          l.pop_front();
        }else{
          l.push_back(l.front());
          l.pop_front();
        }
      }
      if(now==m-1)break;
    }
    l.sort();
    for(int i=1;i<m-now;i++){
      cout <<l.front()<<" ";
      l.pop_front();
    }
    cout <<l.front()<<endl;
    cin >>m >>n;
  }
  return 0;
}