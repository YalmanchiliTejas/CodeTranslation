#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> masu(h, vector<char>(w));
  for(int i = 0; i < h; i++){
	for(int j = 0; j < w; j++){
      cin >> masu.at(i).at(j);
    }
  }
  vector<int>height(h);
  vector<int>width(w);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
	  if(masu.at(i).at(j) == '#'){
        break;
      }else if(j == w-1){
        height.at(i) = 1;
      }
    }
  }
  for(int j = 0; j < w; j++){
	for(int i = 0; i < h; i++){
      if(masu.at(i).at(j) == '#'){
        break;
      }else if(i == h-1){
        width.at(j) = 1;
      }
    }
  }
    
  int end = w - 1;
  for(int j = w-1; j >= 0; j--){
	if(width.at(j) == 1){
	  end--;
    }else{
	  break;
    }
  }
  for(int i = 0; i < h; i++){
    if(height.at(i) == 1){
      	continue;
    }
    for(int j = 0; j < w; j++){
	  if(width.at(j) == 1){
		continue;
      }
      cout << masu.at(i).at(j);
      if(j == end){
        cout << endl;
      }
    }
  }/*
  for(int i = 0; i < h; i++){
	cout << height.at(i);
    if(i == h-1){
      cout << endl;
    }
    else{
      cout << " ";
    }
  }
  for(int j = 0; j < w; j++){
	cout << width.at(j);
    if(j == w-1){
	  cout << endl;
    }
  }
  cout << end << endl;*/
}