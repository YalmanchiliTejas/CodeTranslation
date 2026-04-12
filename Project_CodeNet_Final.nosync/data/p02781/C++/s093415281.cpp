#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string strN;
    int K;
    cin >> strN;
    cin >> K;
    int res = 0;
    vector<int> firstKofN;
    vector<int> posfKoN;

    int nonzerobuf = 0;
    int numdigits = 0;
    int lenN = strN.length();
    if(lenN < K){
        cout << 0 << endl;
        return 0;
    }
    for(char e: strN){
        if(e != '0'){
            nonzerobuf++;
            firstKofN.push_back(e-'0');
            posfKoN.push_back(numdigits);
        }
        if(nonzerobuf >= K)break;
        numdigits++;
    }

    if(firstKofN.size()<K){
        for(int i=firstKofN.size(); i<K; i++){
            firstKofN.push_back(0);
            posfKoN.push_back(lenN-1);
        }
    }

    int resbuf = firstKofN[K-1];
    res += resbuf;

    resbuf = 1;
    if(K>1)resbuf = firstKofN[K-2]-1;
    resbuf *= 9*(lenN-posfKoN[(K-2 < 0 ? 0 : K-2)]-1);
    res += resbuf;

    if(K>1){
        resbuf = 1;
        if(K==3)resbuf*=firstKofN[0]-1;
        resbuf *= 81*(lenN-1)*(lenN-2)/2;
        res += resbuf;
        resbuf = 9*(lenN-posfKoN[K-1]-1);
        res += resbuf;
    }
    if(K>2){
        resbuf = 729*(lenN-1)*(lenN-2)*(lenN-3)/6;
        res += resbuf;
        resbuf = 81*(lenN-posfKoN[K-2]-1)*(lenN-posfKoN[K-2]-2)/2;
        res += resbuf;
    }


    cout << res << endl;

    return 0;
}