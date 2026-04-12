#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

long long int nrnr, sum;

int vec[3005];
long long int ras[3005][3005];

int main()
{
    cin >> nrnr;
    for(int index = 0; index < nrnr; index++){
        cin >> vec[index];
    }
    for(int index = 0; index < nrnr; index++){
        ras[index][index] = vec[index] * (nrnr % 2);
        sum += vec[index];
    }
    for(int index = 1; index < nrnr; index++){
        for(int index2 = 0; index + index2 < nrnr; index2++){
            if((nrnr - index) % 2){
                ras[index2][index + index2] = max(vec[index2] + ras[index2 + 1][index + index2], vec[index + index2] + ras[index2][index + index2 - 1]);
            }
            else{
                ras[index2][index + index2] = min(ras[index2 + 1][index + index2], ras[index2][index + index2 - 1]);
            }
        }
    }
    cout << 2 * ras[0][nrnr - 1] - sum;
    return 0;
}
