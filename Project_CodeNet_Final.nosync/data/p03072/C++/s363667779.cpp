#include<iostream>
#include<vector>

using namespace std;

int main(){

    int N,s;
    cin >> N;

    vector<int> H(N);

    for(int i=0;i<H.size();i++){
        cin >> H[i];
    }

    int view = 1;

    for(int i=1;i<H.size();i++){
        int k = 0;

        for(int j=0;j<i;j++){
            if(H[i]<H[j]){break;}
            
            k++;
        }

        if(k==i){
            view++;
        }
    }

    cout << view << endl;
}