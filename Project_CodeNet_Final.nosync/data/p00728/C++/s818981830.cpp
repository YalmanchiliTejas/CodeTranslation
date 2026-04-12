#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    for(int j=0;j<20;j++){
    int n,sum=0;
    cin >> n;
    if(n==0){
        break;
    }
    vector<int> score(n);
    for(int i=0;i<n;i++){
        cin >> score.at(i);
    }
    sort(score.begin(),score.end());
    for(int i=1;i<n-1;i++){
        sum+=score.at(i);
    }
    cout << sum/(n-2) << endl;
    }
    return 0;
}

