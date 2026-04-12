#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  // input
    int h,w;cin >> h >> w;
    vector<vector<char>> init(h + 1, vector<char>(w + 1));
    for(int i = 1;i < h + 1 ; i++) {
        for(int j = 1; j < w + 1; j++){
            cin >> init[i][j];
        } 
    }
  
    //debug 
    /*
    for(int i = 1;i < h + 1 ; i++) {
      for(int j = 1; j < w + 1; j++){
        cout << init[i][j];
      }
    }   
    */

    vector<vector<int>> a(h + 1, vector<int>(w + 1));
    for(int i = 1;i < h + 1 ; i++) {
        for(int j = 1; j < w + 1; j++){
            if(init[i][j] == '#'){
                a[i][j] = 1;
            }else{
                a[i][j] = 0;
            }
        } 
    }
  
  //debug
   /*
    for(int i = 1;i < h + 1 ; i++) {
        for(int j = 1; j < w + 1; j++){
                cout << a[i][j];
          if(j == w){
                cout << endl;
          }
        } 
    }
    */
  
    

  // compute 
    set<int> st1;
    set<int> st2;
    for(int i = 1;i < h + 1; i++) {
        st1.insert(i);
    }
    for(int i = 1;i < w + 1; i++) {
        st2.insert(i);
    }

    vector<int> check_h(h + 1);
    vector<int> check_w(w + 1);
    for(int i = 1;i < h + 1; i++) {
        check_h[i] = 0;
    }
    for(int i = 1;i < w + 1; i++) {
        check_w[i] = 0;
    }

    for(int i = 1;i < h + 1 ; i++) {
        for(int j = 1; j < w + 1; j++){
            if(a[i][j] == 1){
                check_h[i] = 1;
                break;
            }
        } 
    }

    for(int j = 1;j < w + 1 ; j++) {
        for(int i = 1; i < h + 1; i++){
            if(a[i][j] == 1){
                check_w[j] = 1;
                break;
            }
        } 
    }

    for(int i = 1;i < h + 1 ; i++) {
        if(check_h[i] == 0){
            st1.erase(i);
        }
    }

    for(int i = 1;i < w + 1 ; i++) {
        if(check_w[i] == 0){
            st2.erase(i);
        }
    }

  // output  
    for(int i = 1;i < h + 1 ; i++) {
        	bool p = st1.count(i);
        	if( !p) continue;
      	for(int j = 1; j < w + 1; j++){
			bool q = st2.count(j);
          if(p && q){
            cout << init[i][j];
          }
          if(j == w){
            cout << endl;
          }
        }
    }

}
