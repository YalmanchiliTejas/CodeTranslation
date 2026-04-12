#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    int maxheight=-1;
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        if(maxheight <= H[i])
        {
            counter = counter+1;
            maxheight = H[i];
        }
    }
    cout << counter << endl;   
    return 0;
}