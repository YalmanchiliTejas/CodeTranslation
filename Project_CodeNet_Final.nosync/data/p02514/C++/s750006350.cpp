#include<iostream>
using namespace std;

int main(){
  int n[6];
  int a,b,c;

  while(1){
    for(int i=0;i<6;i++)cin >> n[i];
    bool f = false;
    for(int i=0;i<6;i++){
      if(n[i])f = true;
    }
    if(!f)break;

    a = n[0] + n[3];
    b = n[1] + n[4];
    c = n[2] + n[5];

    int ans = 0;
    if(a){
      ans += (a/3);
      a -= (a/3)*3;
      if(!a){
	a += 3;
	ans -= 1;
      }
    }
    //cout << "[" << ans << "]" << endl;

    if(b){
      ans += (b/3);
      b -= (b/3)*3;
      if(!b){
	b += 3;
	ans -= 1;
      }
    }
    //cout << "[" << ans << "]" << endl;

    if(c){
      ans += (c/3);
      c -= (c/3)*3;
      if(!c){
	c += 3;
	ans -= 1;
      }
    }
    //cout << "[" << ans << "]" << endl;
    //cout << a << " " << b << " " << c << endl;

    if(a>2 && b>2 && c>2)ans += 3;
    else if(a>1 && b>1 && c>1)ans += 2;
    else if( (a==3 && b==3) || (b==3 && c==3) || (c==3 && a==3) )ans += 2;
    else if(a>0 && b>0 && c>0)ans += 1;
    else if(a==3 || b==3 || c==3)ans += 1;

    cout << ans << endl;
  }
}