#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    int i,j;
    int sum=0;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            cin >> a.at(i).at(j);
            if(a.at(i).at(j)=='#')sum++;
        }
    }

    if(sum!=h+w-1)cout << "Impossible" << endl;
    else       cout << "Possible" << endl;
    return 0;
}