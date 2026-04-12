#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> // sort
#include <map> // pair

using namespace std;

int main(){
    int64_t N,X,M;

    cin >> N >> X >> M;

    int64_t sum =X;
    int64_t An = X;

    vector <int> Anarray;
    Anarray.push_back(X);
    int64_t firstlindex =0;
    int64_t lastlindex =0;

    int finflag=0;

    for(int64_t i=1;i<N;i++){

        int temp =  (An *An ) % M;
        if(temp == 0){
            break;
        }
        for(int64_t j =0; j<i;++j){
            if(temp == Anarray[j]){
                firstlindex = j;
                lastlindex = i;
                int loopAnnum = i - j;
                // 繰り返部分
                int64_t loopsum = 0;
                for (int64_t k = j;k<i;k++){
                    loopsum += Anarray[k];
                }

                int64_t tnum = N -i ;//

                int64_t temp1 = tnum/loopAnnum;
                int64_t temp2 = tnum%loopAnnum;

                sum += loopsum*temp1;

                for (int64_t k = 0;k<temp2;k++){
                    sum += Anarray[j+k];
                }
                finflag=1;
                break;

            }
        }
        if(finflag){
            break;
        }


        An = temp;
        Anarray.push_back(An);
        sum += temp;
    }

    cout<< sum <<endl;
}

