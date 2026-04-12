#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N, 0);

    for(auto&& h: H){
        cin >> h;
    }

    int count = 1;

    for (int i = 1; i < N; ++i){

        bool flag = true;

        for (int j = 0; j <= i - 1; ++j){

            if( H[j] > H[i]){
                flag = false;
            }

        }

        if( flag == true){
            ++count;
        }

    }

    cout << count << endl;

    return 0;
}