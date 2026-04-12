#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    int H[100];
    int ans=0;
    int maxH=-1;
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> H[i];
        if(maxH<=H[i]){
            maxH=H[i];
            ans++;
        }
    }

    cout << ans <<endl;
	return 0;
}