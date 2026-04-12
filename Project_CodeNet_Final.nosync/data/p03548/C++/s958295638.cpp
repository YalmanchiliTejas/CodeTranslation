#include<iostream>
using namespace std;
int x, y, z, qaq, ans;
int main()
{
    cin >> x >> y >> z;
    qaq = z;//将qaq初始值定为z（座位末端的人与椅子边缘的间隔为Z厘米长）
    while(qaq + y + z <= x){
        qaq += y + z;//每做一个人要多占要y+z的位置（坐在座位上的人总是占据长度为Y厘米的间隔，两个人之间必须有至少Z厘米的长度差距）
        ans ++;
    }
    cout << ans<<endl;
    return 0;
}