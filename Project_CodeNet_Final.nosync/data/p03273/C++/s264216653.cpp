#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<char>> a2(h,vector<char>(w));
    int i,j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> a.at(i).at(j);
        }
    }
    int tate=0;
    int kie=0;
    for(i=0;i<h;i++){
        int ha=0;
        for(j=0;j<w;j++){
            if(a.at(i).at(j)!='.')
            ha++;
        }
        if(ha!=0){
            for(j=0;j<w;j++)a2.at(i-kie).at(j)=a.at(i).at(j);
            tate++;
        }
        else {
            kie++;
            }
    }
    vector<vector<char>> b(w,vector<char>(tate));
    vector<vector<char>> b2(w,vector<char>(tate));
    for(i=0;i<w;i++){
        for(j=0;j<tate;j++){
            b.at(i).at(j)=a2.at(j).at(i);
        }
    }

    int tate2=0;
    int kie2=0;
    for(i=0;i<w;i++){
        int ha=0;
        for(j=0;j<tate;j++){
            if(b.at(i).at(j)!='.')
            ha++;
        }
        if(ha!=0){
            for(j=0;j<tate;j++)b2.at(i-kie2).at(j)=b.at(i).at(j);
            tate2++;
        }
        else{
            kie2++;
        }
    }
    vector<vector<char>> ans(tate,vector<char>(tate2));
    for(i=0;i<tate;i++){
        for(j=0;j<tate2;j++){
            ans.at(i).at(j)=b2.at(j).at(i);
            cout << ans.at(i).at(j);
        }
        cout << endl;
    }
    return 0;

}