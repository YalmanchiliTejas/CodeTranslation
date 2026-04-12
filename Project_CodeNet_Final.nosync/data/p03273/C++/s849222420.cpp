#include <bits/stdc++.h>
using namespace std;

int main() {
    int H=0, W=0;
    cin >> H >> W;
    vector<vector<char>> pic(H, vector<char>(W, 'e'));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> pic.at(i).at(j);
        }
    }

    //compress hight
    if(W == 1){
        for(int i=0; i<H; i++){
            if(pic.at(i).at(0) == '#'){
                cout << '#';
            }
        }
        cout << endl;
        return 0;
    }
    for(int i=0; i<pic.size(); i++){
        int check = 0;
        for(int j=1; j<W; j++){
            if(pic.at(i).at(0) == '.' && pic.at(i).at(0) == pic.at(i).at(j))
                check++;
        }
        if(check == W-1){
            for(int k=i; k<pic.size()-1; k++){
                swap(pic.at(k), pic.at(k+1));
            }
            pic.pop_back();
            i--;
        }
    }

/*    //output
    cout << endl;
    for(int i=0; i<pic.size(); i++){
        for(int j=0; j<pic.at(0).size(); j++){
            cout << pic.at(i).at(j);
        }
        cout << endl;
    }*/

    //compress width
    if(pic.size() == 1){
        for(int j=0; j<W; j++){
            if(pic.at(0).at(j) == '#')
                cout << '#';
        }
        cout << endl;
    }else{
        for(int j=0; j<pic.at(0).size(); j++){
            int check = 0;
            for(int i=1; i<pic.size(); i++){
                if(pic.at(0).at(j) == '.' && pic.at(0).at(j) == pic.at(i).at(j))
                    check++;
            }
            if(check == pic.size()-1){
                int wi = pic.at(0).size();
                for(int i=0; i<pic.size(); i++){
                    for(int k=j; k<wi-1; k++){
                        swap(pic.at(i).at(k), pic.at(i).at(k+1));
                    }
                    pic.at(i).pop_back();
                }
                j--;
            }
        }

    //output
    cout << endl;
    for(int i=0; i<pic.size(); i++){
        for(int j=0; j<pic.at(0).size(); j++){
            cout << pic.at(i).at(j);
        }
        cout << endl;
    }
    }
}