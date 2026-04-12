#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int h,w;
    cin >> h >>w;
    vector<vector<char>> hai_a(h*2,vector<char>(w*2,'.'));
    vector<int> hai_h(h,0);
    vector<int> hai_w(w,0);
    int cnt_h =0 , cnt_w =0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> hai_a.at(i).at(j);
            if(hai_a.at(i).at(j)=='#'){
                hai_h.at(i)++;
                hai_w.at(j)++;
            }
        }   
    }
    for(int i=0;i<h;i++){
        if(hai_h.at(i)==0){
            cnt_h++;
        }
    }
    for(int j=0;j<w;j++){
        if(hai_w.at(j)==0){
            cnt_w++;
        }
    }
    for(int l=0;l<h;l++){ 
        for(int i=0;i<h;i++){
            bool k=true;
            for(int j=0;j<w;j++){
                if(hai_a.at(i).at(j)!= '.'){
                    k =false;
                }
            }
            if(k == true){
                for(int j=0;j<w;j++){
                    hai_a.at(i).at(j)=hai_a.at(i+1).at(j);
                    hai_a.at(i+1).at(j) = '.';
                }
            }
        }
    }
    for(int l=0;l<w;l++){
        for(int i=0;i<w;i++){
            bool k=true;
            for(int j=0;j<h;j++){
                if(hai_a.at(j).at(i)!= '.'){
                    k =false;
                }
            }
            if(k == true){
                for(int j=0;j<h;j++){
                    hai_a.at(j).at(i)=hai_a.at(j).at(i+1);
                    hai_a.at(j).at(i+1) = '.';
                }
            }
        }
    }
    vector<vector<char>> hai_ans(h-cnt_h,vector<char>(w-cnt_w,'.'));
    for(int i=0;i<h-cnt_h;i++){
        for(int j=0;j<w-cnt_w;j++){
            hai_ans.at(i).at(j) = hai_a.at(i).at(j);
            if(j!=w-cnt_w-1){
                cout << hai_ans.at(i).at(j);
            }else{
                cout << hai_ans.at(i).at(j) <<endl;
            }
        }
    }

}