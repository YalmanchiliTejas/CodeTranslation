#include<iostream>
#include<vector>

using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char> > a(H,vector<char> (W));

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a.at(i).at(j);
        }
    }

    vector<int> h(H),w(W);

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(a.at(i).at(j)=='#'){
                h.at(i) = 1;
                break;
            }else{
                h.at(i) = 0;
            }
        }
    }

    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(a.at(j).at(i)=='#'){
                w.at(i) = 1;
                break;
            }else{
                w.at(i) = 0;
            }
        }
    }

    for(int i=0;i<H;i++){
        if(h.at(i)==1){
            for(int j=0;j<W;j++){
                if(w.at(j)==1){
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }

    return 0;

}