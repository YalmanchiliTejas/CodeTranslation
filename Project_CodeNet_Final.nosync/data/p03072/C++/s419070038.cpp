#include <iostream>
//#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
//        ifstream in("input.txt");
//        cin.rdbuf(in.rdbuf());
    
    int N;
    cin >> N;
    
//    vector<int> h(N);
    int H;
    int maxH=0;
    int cnt = 0;
    for (int i=0;i<N;++i)
    {
        cin >> H;
        if (H >= maxH)
        {
            ++cnt;
            maxH = H;
        }
    }
    
    cout << cnt << endl;
    
    
    
    return 0;
}