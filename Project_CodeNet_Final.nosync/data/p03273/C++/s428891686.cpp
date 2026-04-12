#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i=0;i<H;i++){
        cin >> S[i];
    }
    bool jg=true;
        jg=false;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                
                if(S[i][j]=='#') break;
                else if(j==W-1){
                    S.erase(S.begin()+i);
                    i--,H--;
                    jg=true;
                }
            }
        }

        for(int i=0;i<W;i++){
            for(int j=0;j<H;j++){
                if(S[j][i]=='#') break;
                else if(j==H-1){
                    for(int l=0;l<H;l++){
                        S[l]=S[l].substr(0,i)+S[l].substr(i+1,W-i-1);;
                    }
                    i--,W--;
                }
            }
        }
    cout << endl;
    for(int i=0;i<H;i++){
        cout << S[i] << endl;
    }
}