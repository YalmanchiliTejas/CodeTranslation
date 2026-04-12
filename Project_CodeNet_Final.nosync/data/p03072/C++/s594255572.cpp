#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

int main(){
    unsigned int N;
    cin >> N;
    vector<unsigned int> H(N);
    for(int i = 0; i < N; i++)  cin >> H[i];

    unsigned int maxH, sum;
    
    /* i = 1 */
    maxH = H[0];
    sum = 1;

    for(int i = 1; i < N; i++){
        if(H[i] >= maxH){
            sum++;
            maxH = H[i];
        }
    }

    cout << sum << endl;

    return 0;
}