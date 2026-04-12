#include <iostream>
#include <algorithm>

using namespace std;
int an[30];


int main()
{
    int n;
    cin>>n;
    int key = 0;
    int ans = 0;
    for (int i = 0;i < n;i++)cin>>an[i];
    for (int i = 1;i < n;i++){
        for (int j = i-1;j >= 0;j--){
            if (an[i] < an[j]){
                key = -1;
                break;
            }
        }
        if (key == 0){
            ans++;
        }
        key = 0;
    }
    cout<<ans+1<<endl;
    return 0;
}