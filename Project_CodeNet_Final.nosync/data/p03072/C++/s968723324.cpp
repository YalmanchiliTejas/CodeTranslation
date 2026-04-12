#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >>n;

    vector<int> h;


    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >>tmp;
        bool visible = true;
        for(int j = 0; j < h.size(); j++){
            if(h[j] > tmp){
                visible = false;
                break;
            }
        }
        if(visible){
            ans++;
        }
        h.push_back(tmp);
    }
    printf("%d\n", ans);
    return 0;
}