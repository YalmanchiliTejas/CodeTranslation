#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> H(N);
    for(auto i=0;i<N;i++)
        cin >> H.at(i);

    int count = 1;

    for(auto i=1;i<N;i++){
        int tmp=0;
        for(auto j=0;j<i;j++){
            if(H.at(j)<=H.at(i))
                tmp++;
            else
                break;
        }
        if(tmp==i)
            count++;
    }

    cout << count << endl;
    return 0;
}