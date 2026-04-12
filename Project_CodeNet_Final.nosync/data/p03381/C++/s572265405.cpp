#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> vect(N);
    vector<long long> inp(N);
    for(int i=0; i< N; i++){
        cin >> vect[i];
        inp[i] = vect[i];
    }

    sort(vect.begin(), vect.end());
    int low = vect[N/2 -1 ];
    int high = vect[N/2];
    for(int i=0 ; i< N ; i++){
        if( inp[i] <= low){
            cout << high << endl;
        }else{
            cout << low << endl;
        }
    }

    return 0;
}
