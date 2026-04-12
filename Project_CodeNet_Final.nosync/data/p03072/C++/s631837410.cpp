#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }

    int count = 0, max_height=-1;
    for(int i=0;i<N;i++){
        if(H[i] >= max_height) ++count;
        max_height = max(max_height, H[i]);
    }
    cout << count << endl;
}