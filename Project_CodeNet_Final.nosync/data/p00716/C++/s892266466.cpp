#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    int m;
    
    cin >> m;
    
    for(int i=0; i<m; i++){
        int A, y, n, e=0, d=0;
        double c=0;
        priority_queue<int> maxpq;
        
        cin >> A;
        cin >> y;
        cin >> n;
        
        for(int j=0; j<n; j++){
            int ans=A;
            int B=0, S=0;
            scanf("%d %lf %d", &e, &c, &d);
            
            if(e==0){
                for(int k=0; k<y; k++){
                    B = ans*c;
                    ans -= d;
                    S += B;
                }
                maxpq.push(ans+S);
            }
            if(e==1){
                for(int k=0; k<y; k++){
                    B = ans*c;
                    ans = ans+B-d;
                }
                maxpq.push(ans);
            }
        }
        
        cout<<maxpq.top()<<endl;
        //maxpq.pop();
       // cout<<maxpq.top()<<endl;
        
    }

    return 0;
}