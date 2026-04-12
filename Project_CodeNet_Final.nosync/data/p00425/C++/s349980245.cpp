#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()

using namespace std;

vector<int> arr;
int top, bottom;

void north()
{
    swap(arr[2], top);
    swap(top, arr[0]);
    swap(arr[0], bottom);
}

void east()
{
    swap(arr[1], top);
    swap(top, arr[3]);
    swap(arr[3], bottom);
}

void right()
{
    swap(arr[0], arr[1]);
    swap(arr[1], arr[2]);
    swap(arr[2], arr[3]);
}

int main(int argc, char const* argv[])
{
    while (1) {
        arr = { 2, 3, 5, 4 };
        top = 1, bottom = 6;
        int T; cin >> T;
        if (!T) break;
        int ans = 1;
        while (T--) {
            string cmd; cin >> cmd;
            if (cmd == "North") north();
            if (cmd == "South") loop (3, i) north();
            if (cmd == "East") east();
            if (cmd == "West") loop (3, i) east();
            if (cmd == "Right") right();
            if (cmd == "Left") loop (3, i) right();
            ans += top;
        }
        cout << ans << endl;
    }
    return 0;
}