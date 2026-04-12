#include <bits/stdc++.h>
using namespace std;

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
 
  for (int w_i = 0; w_i < H; w_i++) {
	for (int h_i = 0; h_i < W; h_i++) {
    		cin >> data.at(w_i).at(h_i);
	}
  }

 vector<vector<char>> yoko_data(W, vector<char>(H));
  
  //yoko data input
  for (int w_i = 0; w_i < H; w_i++) {
	for (int h_i = 0; h_i < W; h_i++) {
        yoko_data.at(h_i).at(w_i) =  data.at(w_i).at(h_i);
	}
	//cout<<endl;
  }
  
  //yoko print
  /*
  for (int w_i = 0; w_i < W; w_i++) {
	for (int h_i = 0; h_i < H; h_i++) {
    		cout <<  yoko_data.at(w_i).at(h_i);
	}
	cout<<endl;
  }*/
  
//yoko wo kesu
  
  vector<int> v; 
  int count_h=0;
  int count_w=0;
  int point_h=0;
  
  for (int w_i = 0; w_i < H; w_i++) {
  	count_w=0;
	for (int h_i = 0; h_i < W; h_i++) {
    		if(data.at(w_i).at(h_i)=='.'){
    			count_w+=1;
    		}
    		point_h=w_i;
	
	if(count_w==W){
		v.push_back(point_h);
		point_h=0;
	}
	}
  }
  
  vector<int> v2; 
  int count_h2=0;
  int count_w2=0;
  int point_h2=0;
  
  for (int w_i = 0; w_i < W; w_i++) {
  	count_w2=0;
	for (int h_i = 0; h_i < H; h_i++) {
    		if(yoko_data.at(w_i).at(h_i)=='.'){
    			count_w2+=1;
    		}
    		point_h2=w_i;
	
	if(count_w2==H){
		v2.push_back(point_h2);
		point_h2=0;
	}
	}
  }
;
  for (int w_i = 0; w_i < H; w_i++) {
  //yoko
  	if(vector_finder(v,w_i)==1){
  		continue;
  	}
	for (int h_i = 0; h_i < W; h_i++) {
    	if(vector_finder(v2,h_i)==1){
  		continue;
  	    }
       cout <<  data.at(w_i).at(h_i);
	}
	cout<<endl;
  }


}
