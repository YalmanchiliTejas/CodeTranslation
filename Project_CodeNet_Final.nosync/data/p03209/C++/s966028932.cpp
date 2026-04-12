#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
typedef pair<ul, ul> P;



int main()
{
    
    int N;
    uint64_t X;
    cin >> N >> X;

    int count = N;

    uint64_t sum = 0;
    while(count>=0){

        if(X<=0){
            break;
        }

        else if(X==1){
            if(count==0){
                sum += 1;
                break;
            }else{
                sum += 0;
                break;
            }
        }else if(X>1 &&X<pow(2, count+1)-3+2){
            
            X -= 1;
        }
        else if (X == pow(2, count+1)-3+2)
        {
            sum += pow(2, count);
            break;
        }
        else if(X<pow(2,count+2)-3){
            sum += pow(2, count);
            X -= (pow(2, count+1)-3 + 2);
        }
        else
        {
            sum += pow(2, count+1) - 1;
            break;
        }
        count -= 1;
    }

    cout << sum << endl;
    

}
