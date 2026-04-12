#include <iostream>
using namespace std;

string partsorw(bool spe[], int n, string xo){

    bool around0 = false;
    bool aroundn1 = false;
    bool shougen0 = false;
    bool shougenn1 = false;
    bool ok0 = false;
    bool okn1 = false;

    string example = "";

    for(int i = 1; i < n - 1; i++){
        if((spe[i] && xo[i] == 'o') || (!spe[i]) && xo[i] == 'x'){
            spe[i + 1] = spe[i - 1];
        } else{
            spe[i + 1] = !spe[i - 1];
        }
    }
    
    if(spe[n - 1] == spe[1])
        around0 = true;

    if (spe[n - 2] == spe[0])
        aroundn1 = true;

    if((spe[0] && xo[0] == 'o') || (!spe[0] && xo[0] == 'x'))
        shougen0 = true;

    if((spe[n - 1] && xo[n - 1] == 'o') || (!spe[n - 1] && xo[n - 1] == 'x'))
        shougenn1 = true;

    if (around0 == shougen0)
        ok0 = true;

    if (aroundn1 == shougenn1)
        okn1 = true;

    if(ok0 && okn1){
            for (int k = 0; k < n; ++k) {
                if (spe[k]) {
                    example += "S";
                } else {
                    example += "W";
                }
            }
        }

    return example;
}

string sorw(int n, string xo){
    bool speicies[n];
    string TT, TF, FT, FF;
    speicies[0] = true;
    speicies[1] = true;
    TT = partsorw(speicies, n, xo);
    speicies[0] = true;
    speicies[1] = false;
    TF = partsorw(speicies, n, xo);
    speicies[0] = false;
    speicies[1] = true;
    FT = partsorw(speicies, n, xo);
    speicies[0] = false;
    speicies[1] = false;
    FF = partsorw(speicies, n, xo);
    if (TT != ""){
        return TT;
    } else {
        if (TF != ""){
            return TF;
        } else {
            if (FT != ""){
                return FT;
            } else {
                if (FF != ""){
                    return FF;
                } else {
                    return "-1";
                }
            }
        }
    }

}

int main() {
    int N;
    string xoro;
    cin >> N >> xoro;
    string Ans = sorw(N, xoro);
    cout << Ans << endl;
    return 0;
}