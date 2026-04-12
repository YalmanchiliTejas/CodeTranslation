#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    int N;
    int height[21];
    int count = 0;
    int tmp = 0;
    cin >> N;
    for(int i=0; i<N; i++)  cin >> height[i];

    for(int i=0; i<N; i++){
        for(int j=i; j>=0; j--){

            if(height[i] < height[j])   tmp++;
        }
        if(tmp != 0)    count ++;
        tmp = 0;
    }

    cout << N - count;

}