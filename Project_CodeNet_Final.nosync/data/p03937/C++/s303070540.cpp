#include<iostream>
using namespace std;
int main(){
	int H,W;
  	cin >> H >> W;
  	int ans =0;
  	for(int i=0;i<H;i++)
      for(int j=0;j<W;j++){
      	char c;
        cin >> c;
        ans += c=='#'?1:0;
      }
  	cout << (ans==H+W-1?"Possible":"Impossible");
}