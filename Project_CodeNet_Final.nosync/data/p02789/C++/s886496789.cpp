/***********************************************
 *                   _ooOoo_                   *
 *                  o8888888o                  *
 *                  88" . "88                  *
 *                  (| -_- |)                  *
 *                  O\  =  /O                  *
 *               ____/`---'\____               *
 *             .'  \\|     |//  `.             *
 *            /  \\|||  :  |||//  \            *
 *           /  _||||| -:- |||||-  \           *
 *           |   | \\\  -   * |    |           *
 *           | \_|  ''\---/''  |   |           *
 *           \  .-\__  `-`  ___/-. /           *
 *         ___`. .'  /--.--\  `. . __          *
 *      ."" '<  `.___\_<|>_/___.'  >'"".       *
 *     | | :  `- \`.;`\ _ /`;.`/ - ` : | |     *
 *     \  \ `-.   \_ __\ /__ _/   .-` /  /     *
 *======`-.____`-.___\_____/___.-`____.-'======*
 *                   `=---='                   *
 *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

             佛祖保佑       永无BUG

   本程序已经经过开光处理，绝无可能再产生bug
 **********************************************/
#include<algorithm>
#include <iostream>
#include  <cstdlib>
#include  <cstring>
#include   <string>
#include   <vector>
#include   <cstdio>
#include    <queue>
#include    <stack>
#include    <ctime>
#include    <cmath>
#include      <map>
#include      <set>
#define ll long long
#define INF 0x3f3f3f3f
#define db1(x) cout<<#x<<"="<<(x)<<endl
#define db2(x,y) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<endl
#define db3(x,y,z) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<", "<<#z<<"="<<(z)<<endl
using namespace std;

int main(void)
{
    #ifdef test
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
    clock_t start=clock();
    #endif //test

    int N,M;
    scanf("%d%d",&N,&M);
    if(N==M)printf("Yes\n");
    else printf("No\n");
    
    #ifdef test
    clockid_t end=clock();
    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\n\n\n\n");
    cout<<"Total time:"<<endtime<<"s"<<endl;        //s为单位
    cout<<"Total time:"<<endtime*1000<<"ms"<<endl;    //ms为单位
    #endif //test
    return 0;
}


// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ????━????   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━
