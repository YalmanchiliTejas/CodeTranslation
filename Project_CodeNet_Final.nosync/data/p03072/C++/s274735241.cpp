#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    int ans = 1;
    int max = v[0];
    for(int i = 1; i < n; i++)
    {
        if(v[i] >= max) {
            ans++;
            max = v[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
