#include <iostream>
#include <stack>
#define N 100005
using namespace std;

int main(){
  bool table[N];
  while(1){
    int n;
    int ans=0;
    cin >> n;
    if(n==0) break;

    int start;
    stack<int> p;
    p.push(0);
    cin >> start;
    if(start){
      table[0]=true;
    }
    else{
      table[0]=false;
      ans++;
    }
    for(int i=1;i<n;i++){
      int next;
      cin >> next;
      if(i%2){
        if(next){
          if(table[i-1]==true){
            table[i]=true;
          }
          else{
            table[i]=true;
	    int temp=p.top();
	    p.pop();
            ans-=i-temp;
	    if(temp==0) p.push(0);
          }
        }
        else{
	  ans++;
          if(table[i-1]==false){
            table[i]=false;
          }
          else{
            table[i]=false;
	    int temp=p.top();
	    p.pop();
            ans+=i-temp;
	    if(temp==0) p.push(0);
          }
        }
      }
      else{
        if(next) table[i]=true;
        else{
	  table[i]=false;
	  ans++;
	}
	if(table[i]!=table[i-1]){
	  p.push(i);
	}
      }
    }
    cout <<  ans << endl;
  }
  return 0;
}