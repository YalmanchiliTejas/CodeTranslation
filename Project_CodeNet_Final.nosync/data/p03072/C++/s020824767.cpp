#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,i,ans = 0,j;
    cin >> n;
    vector<int> h(n);
    for(i = 0;i < n;++i){
        cin >> h.at(i);
    }
    for(i = 0;i < n;++i){
        int max = 0;
        for(j = 0;j <= i;++j){
            if(max < h.at(j)){
                max = h.at(j);
            }
        }
        if(max == h.at(i)){
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}