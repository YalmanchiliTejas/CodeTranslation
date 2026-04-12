#define _USE_MATH_DEFINES
#include <sstream> //string stream its useful!
#include<string>
#include<iostream>
#include<utility> //pair
#include <vector> // vector
#include <algorithm>    // swap,sort,binary_search
#include <functional>   // std::greater
#include <map> //map
#include<set> //set
#include<queue> //queue
#include<list> //list
#include<cmath>
#include<numeric>
#include<cassert>
#include <iomanip> //cout<<setprecision

typedef long long ll;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

using namespace std;
void omajinai() {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(15);
    //freopen("txt.csv","r",stdin);
}


int main(){
    omajinai();
    int H,W; cin>>H>>W;
    vector<vector<char > > A(H,vector<char>(W,' '));
    for(int i = 0 ; i<H;i++) for(int j = 0; j<W;j++) cin>>A[i][j];
    int nowi = 0, nowj = 0;
    while(true){
        bool upleftcondition = (nowi-1>0 && A[nowi-1][nowj] == '#')&&(nowj-1>0 && A[nowi][nowj-1] == '#');
        if (upleftcondition){
            cout<<"Impossible"<<endl;
            exit(0);
        }
        if(nowi==H-1 && nowj == W-1) break;
        bool tate = nowi+1<H&&A[nowi+1][nowj] == '#';
        bool yoko = nowj+1<W&&A[nowi][nowj+1] == '#';
        if (!(tate^yoko)){
            cout<<"Impossible"<<endl;
            exit(0);
        }
        if(tate) nowi++;
        if(yoko) nowj++;
    }
    cout<<"Possible"<<endl;
    
}