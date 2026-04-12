
#include <iostream>
#include <string.h>
using namespace std;

class Dyce{
    int Top, Bottom, North, East, West, South;
    int temp;
public:
    Dyce(){
        reset(1,2,3);
    }
    Dyce(int iTop, int iSouth, int iEast){
        reset(iTop, iSouth, iEast);
    }
    void reset(int iTop, int iSouth, int iEast);
    int getTop(){return Top;}
    void printNow();
    void toNorth();
    void toEast();
    void toWest();
    void toSouth();
    void toRight();
    void toLeft();
};

void Dyce::reset(int iTop, int iSouth, int iEast){
    Top= iTop;//Top
    Bottom = 7-iTop;//Bottom
    South = iSouth;//South
    North = 7-iSouth;//North
    East = iEast;//East
    West = 7-iEast;//West
}

void Dyce::toNorth(){
    temp = Top;
    Top = South;
    South = Bottom;
    Bottom = North;
    North = temp;
}

void Dyce::toSouth(){
    temp = Top;
    Top = North;
    North = Bottom;
    Bottom = South;
    South = temp;
}

void Dyce::toEast(){
    temp = Top;
    Top = West;
    West = Bottom;
    Bottom = East;
    East = temp;
}

void Dyce::toWest(){
    temp = Top;
    Top = East;
    East = Bottom;
    Bottom = West;
    West = temp;
}

void Dyce::toRight(){
    temp = North;
    North = West;
    West = South;
    South = East;
    East = temp;
}

void Dyce::toLeft(){
    temp = North;
    North = East;
    East = South;
    South = West;
    West = temp;
}

void Dyce::printNow(){
    cout<<"Top"<<Top<<endl;
    cout<<"North"<<North<<endl;
    cout<<"Bottom"<<Bottom<<endl;
    cout<<"South"<<South<<endl;
    cout<<"East"<<East<<endl;
    cout<<"West"<<West<<endl;
}

int main(int argc, const char * argv[])
{
    
    Dyce oDyce(1,2,3);
    int sum;
    
    for(int n;cin>>n,n;){
        oDyce.reset(1,2,3);
        sum = 0;
        sum += oDyce.getTop();
        while(n--){
            string s;cin>>s;
            if(s=="North"){
                oDyce.toNorth();
            }else if(s=="South"){
                oDyce.toSouth();
            }else if(s=="East"){
                oDyce.toEast();
            }else if(s=="West"){
                oDyce.toWest();
            }else if(s=="Right"){
                oDyce.toRight();
            }else if(s=="Left"){
                oDyce.toLeft();
            }
            sum += oDyce.getTop();
        }
        cout<<sum<<endl;
    }
    return 0;
}