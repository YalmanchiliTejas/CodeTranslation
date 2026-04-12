#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main(){
 	int H,W;
  	cin >> H >> W;
  	vector<int> hh(H,0),ww(W,0);
  	vector< vector<char> > a(H,vector<char>(W));
  	for(int i = 0 ; i < H ; i ++){
     	for(int I = 0 ; I < W ; I ++){
         	cin >> a.at(i).at(I);
          	if(a.at(i).at(I) == '#'){
              hh.at(i)++;
              ww.at(I)++;
            }
        }
    }
  	for(int i = 0 ; i < H ; i ++){
     	for(int I = 0 ; I < W ; I ++){
          	if(ww.at(I) != 0 && hh.at(i) != 0) cout << a.at(i).at(I); 
        }
      	if(hh.at(i) != 0)cout << endl;
    }
}