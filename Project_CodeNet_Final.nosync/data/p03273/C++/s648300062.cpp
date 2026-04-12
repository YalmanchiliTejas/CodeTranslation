#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a.at(i).at(j);
        }
    }

    for(int i=h-1;i>=0;i--){
        int count = 0;
        for(int j=0;j<w;j++){
            if(a.at(i).at(j) != '.'){
                break;
            }
            count++;
        }
        if(count == w){
            a.erase(a.begin() + i);
        }
    }

    h = a.size();
    for(int i=w-1;i>=0;i--){
        int count = 0;
        for(int j=0;j<h;j++){
            if(a.at(j).at(i) != '.'){
                break;
            }
            count++;
        }
        if(count == h){
            for(int j=0;j<h;j++){
                a.at(j).erase(a.at(j).begin() + i);
            }
        }
    }

    w = a.at(0).size();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<a.at(i).at(j);
        }
        cout<<endl;
    }
}