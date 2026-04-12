#include <iostream>
using namespace std;
 
int
main(int argc, char *argv[])
{
        int n;
        cin >> n;
        int data[n];
        int i=0;
        while(i<n){
            cin >> data[i];
            i++;
        }

        int counter;
        int answer=1;
        int tmp=data[0];
        for(int x=1;x<n;x++){
            if(data[x-1]<=data[x]&&tmp<=data[x]){
                tmp=data[x];
                answer++;
            }
        }

        cout << answer << endl;

        return 0;
}