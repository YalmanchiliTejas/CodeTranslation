#include<iostream>
#include <fstream>

#define LOCAL  1
#define UPLOAD 2

using namespace std;

int calcDist(int x, int y, int x2, int y2){
    return abs(x2-x) + abs(y2-y);
}

int main()
{
#if ENVIRONMENT == LOCAL
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif

    int n;
    cin >> n;

    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    
    int ret = 1;

    for(int i=1;i<n;i++){
        int max = 0;
        for(int j=0;j<i;j++){
            if(max < h[j]){
                max = h[j];
            }
        }

        if(h[i] >= max){
            ret++;
        }
    }

    cout << ret << endl;

    return 0;
}