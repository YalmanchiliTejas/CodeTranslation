#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int H[N];
    for(int i=0;i<N;i++) cin >> H[i];

    int mireru=H[0];
    int ans=1;
    for(int i=1;i<N;i++){
        if(mireru<=H[i]){
            mireru = H[i];
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}