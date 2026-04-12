#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;


int main(){
    int N;
    cin >> N;

    uint64_t Ai[200001]={};

    uint64_t sum = 0;
    for(int i=0;i<N;++i){
        cin >> Ai[i];
        sum += Ai[i];
    }

    uint64_t divnum = (uint64_t) (1*pow(10,9)+7); 
    uint64_t outnum =0;
    for(int i=0; i< N-1;++i){
        uint64_t temp;
        sum -= Ai[i]; 
        temp = sum % divnum;

        temp = temp * Ai[i];
        temp = temp % divnum;
        outnum += temp;
        outnum = outnum % divnum;
    }

    cout<< outnum <<endl;
}

