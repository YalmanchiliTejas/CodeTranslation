#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int prev,group[200200],n,i,stone,ans,pnt;
    cin >> n;
    while(n!=0){
        fill(group,group+2*n+1,0);
        group[n]=1;
        pnt = n;
        ans = 0;
        cin >> prev;
        if(prev == 0){
            ans++;
        }
        for(i=1; i<n; i++){
            cin >> stone;
            if(prev == stone){
                group[pnt]++;
            }else if(i%2==0){
                pnt++;
                group[pnt]=1;
            }else{
                if(stone==0){
                    ans += group[pnt];
                }else{
                    ans -= group[pnt];
                }
                pnt--;
                group[pnt] += group[pnt+1];
                group[pnt] ++;
            }
            prev = stone;
            if(stone == 0){
                ans++;
            }
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}