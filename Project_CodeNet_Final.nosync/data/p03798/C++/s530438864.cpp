#include<bits/stdc++.h>
using namespace std;


int N;
string s;

string solve(string b){

  for(int i = 0; i < N-2; i++){
    int j = (i+1)%N;
    if(s[j] == 'o'){
      if(b[j] == 'S') b += b[j-1];
      else b += b[j-1]=='W'?'S':'W';
    } else {
      if(b[j] == 'W') b += b[j-1];
      else b += b[j-1]=='W'?'S':'W';
    }
  }
  //cout<<b<<endl;
  if(s[0] == 'o'){
    if(b[0] == 'S' && b[N-1] != b[1]) return "X";
    if(b[0] == 'W' && b[N-1] == b[1]) return "X";
  } else {
    if(b[0] == 'S' && b[N-1] == b[1]) return "X";
    if(b[0] == 'W' && b[N-1] != b[1]) return "X";
  }
  
  if(s[N-1] == 'o'){
    if(b[N-1] == 'S' && b[N-2] != b[0]) return "X";
    if(b[N-1] == 'W' && b[N-2] == b[0]) return "X";
  } else {
    if(b[N-1] == 'S' && b[N-2] == b[0]) return "X";
    if(b[N-1] == 'W' && b[N-2] != b[0]) return "X";
  }

  return b;
  
}

int main(){

  string temp;
  cin>>N;
  cin>>s;
  
  if((temp = solve("SW")) != "X"){
    cout<<temp<<endl;
  } else if((temp = solve("WS")) != "X"){
    cout<<temp<<endl;
  }  else if((temp = solve("WW")) != "X"){
    cout<<temp<<endl;
  }else  if((temp = solve("SS")) != "X"){
    cout<<temp<<endl;
  }else {
    cout<<-1<<endl;
  }



    
  return 0;
}
