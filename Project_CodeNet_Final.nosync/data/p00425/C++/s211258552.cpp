#include<iostream>
#include<string>
using namespace std;
 
int temp;
 
class dice {
public:
        int y, miny, x, minx, z, minz;
        dice() { y = 1, miny = 6, minz = 2, z = 5, x = 3, minx = 4; }
        void North(dice& a){
                temp = y;
                y = minz;
                minz = miny;
                miny = z;
                z = temp;
        }
        void South(dice& a){
                temp = z;
                z = miny;
                miny = minz;
                minz = y;
                y = temp;
        }
        void West(dice& a){
                temp = y;
                y = x;
                x = miny;
                miny = minx;
                minx = temp;
        }
        void East(dice& a){
                temp = minx;
                minx = miny;
                miny = x;
                x = y;
                y = temp;
        }
        void Left(dice& a){
                temp = minz;
                minz = minx;
                minx = z;
                z = x;
                x = temp;
        }
        void Right(dice& a){
                temp = x;
                x = z;
                z = minx;
                minx = minz;
                minz = temp;
        }
};
 
int main(){
        int n,result;
        string d;
        while(cin>>n){
                if(n==0) break;
                dice a;
                result = 0;
                while(n--){
                        cin>>d;
                        if(d == "North") a.North(a);
                        else if(d == "South") a.South(a);
                        else if(d == "West") a.West(a);
                        else if(d == "East") a.East(a);
                        else if(d == "Left") a.Left(a);
                        else if(d == "Right") a.Right(a);
                        result += a.y;
                }
                cout<<result+1<<endl;
        }
}