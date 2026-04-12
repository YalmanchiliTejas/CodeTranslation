#include <iostream>
using namespace std;

#ifdef DEBUG
    #define IFD if(true)
#else
    #define IFD if(false)
#endif

int main()
{
    int N;
    int h, ans = 0, Hm = 0;

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> h;
        if(Hm <= h) {
            ans++;
            Hm = h;
        }
    }
    cout << ans << endl;

    return 0;
}
