#include<bits/stdc++.h>
using namespace std;

int main(){
    int h , w;
    cin >> h >> w;
    int i, j;
    vector<vector<char>> a(h, vector<char>(w));
    for(i = 0;i < h;i++){
        for(j = 0;j < w;j++){
            cin >> a.at(i).at(j);
        }
    }

    for(i = 0;i < a.size();i++){
        for(j = 0;j < w;j++){
            if(a.at(i).at(j) != '.'){
                break;
            }
        }
        if(j == w){
            a.erase(a.begin()+i);
            i--;
        }
    }

    vector<vector<char>> tmp( w, vector<char>( a.size() ) );
    for(i = 0;i < a.size();i++){
        for(j = 0;j < w;j++){
            tmp.at(j).at(i) = a.at(i).at(j);
        }
    }
    /*
    for(i = 0;i < w;i++){
        for(j = 0;j < a.size();j++){
            cout << tmp.at(i).at(j);
        }
        cout << endl;
    }
    */

    for(i = 0;i < tmp.size();i++){
        for(j = 0;j < a.size();j++){
            if(tmp.at(i).at(j) != '.'){
                break;
            }
        }
        if(j == a.size()){
            tmp.erase(tmp.begin()+i);
            i--;
        }
    }

    vector<vector<char>> answer(tmp.at(0).size(), vector<char>(tmp.size()));
    for(i = 0;i < tmp.size();i++){
        for(j = 0;j < tmp.at(0).size();j++){
            answer.at(j).at(i) = tmp.at(i).at(j);
        }
    }

    for(i = 0;i < answer.size();i++){
        for(j = 0;j < answer.at(0).size();j++){
            cout << answer.at(i).at(j);
        }
        cout << endl;
    }


}