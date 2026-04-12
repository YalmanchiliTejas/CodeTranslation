//所有算法都與數據結構的實現細節分開，並由迭代器參數化
#include <algorithm>
#define 填(下, 上, 值) fill(下, 上, 值)
//#define 找(下, 上, 值) find(下, 上, 値)
#define 各(配列, 數) for_each(始(配列), 始(配列) + 數, [](旗 值) { 輸出(值) << " "; })
#define 以上(下, 上, 基準) lower_bound(下, 上, 基準)
#define 最大(下, 上) max_element(下, 上)
//#define 拼(一下, 一上, 二下, 二上) merge(一下, 一上, 二下, 二上, back_inserter(果))
#define 最小(下, 上) min_element(下, 上)
#define 逆(下, 上) reverse(下, 上)
#define 理(下, 上) sort(下, 上)
#define 逆理(下, 上) sort(下, 上, greater<整>())
#define 獨(下, 上) unique(下, 上)
#define 比大(下, 上, 基準) upper_bound(下, 上, 基準)

//最大值
#include <climits>

//數學,標題提供常見的數學函數和各種宏
#include <cmath>
#define 距離(數) abs(數)
#define 切下(數) floor(數)
#define 切上(數) ceil(數)
#define 根(數) sqrt(數)
#define 單縱(角度) sin(角度)
#define 單橫(角度) cos(角度)

//標準輸入輸出
#include <iostream>
#define 輸入(值) cin >> 值
#define 輸出(值) cout << 值

//迭代器
#include <iterator>
#define 始(迭代器) (迭代器).begin()
#define 終(迭代器) (迭代器).end()

//地圖,獨特的元件的一種關聯容器的存儲該密鑰與其相對應的值造
#include <map>
#define 計(值) count(值);

//隊列,關於先進先出隊的列類和具有優先級隊列的類
#include <queue>
#define 行(隊列) 隊列.pop()
#define 推(隊列, 值) 隊列.push(值)
#define 先(隊列) 隊列.front()

//堆,關於後進先出容器適配器
#include <stack>
#define 上(容器) 容器.top()

//集,表示一組關聯容器,二叉樹
#include <set>
//#define 找(集, 值) 集.find(值)

//字符串相關的類，函數和字符特徵
#include <string>
#define 長(字串) 字串.length()
#define 部字(字串, 始, 長) 字串.substr(始, 長)

//効用,標題定義了庫中其餘部分使用的許多基本函數和類模板
#include <utility>
#define 一(組) 組.first
#define 二(組) 組.second
#define 組(一, 二) make_pair(一, 二)
#define 換(一, 二) swap(一, 二)

//向量,一個可變長度數組
#include <vector>
#define 去(向量) (向量).clear()
#define 空(向量) 向量.empty()
#define 除(向量, 值) 向量.erase(值)
#define 插(向量, 值) 向量.insert(值)
#define 添(向量, 值) 向量.push_back(值)
#define 變長(向量, 長) 向量.resize(長)

//論理
#define 如(條件) if (條件)
#define 如他(條件) else if (條件)
#define 他 else

//循環
#define 再(變數, 下, 上) for (整 變數 代 下; 變數 <= 上; 變數 代 變數 + 1)
#define 逆再(變數, 下, 上) for (整 變數 代 上; 變數 >= 下; 變數 代 變數 - 1)
#define 在(條件) while (條件)
#define 斷 break
#define 次 continue

//基本
#define 心() main()
#define 返 return

//演算子
#define 代 =
#define 是 ==
#define 且 &&
#define 又 ||
#define 共 &
#define 累 <<
#define 逆累 >>

#define 構 struct
#define 定 const
#define 真 true
#define 偽 false
#define 空行 endl

//標準下
using namespace std;

//中文型繁
typedef bool 旗;
typedef char 字;
typedef double 小;
typedef int 整數;
typedef long long 整;
typedef string 字串;
typedef void 無;
typedef map<整, 整> 整組;
typedef map<整, 字串> 字組;
typedef pair<整, 整> 整對;
typedef pair<小, 小> 小對;
typedef pair<整, 小> 整小對;
typedef priority_queue<整> 優隊;
typedef queue<整> 整隊;
typedef queue<整對> 整對隊;
typedef set<整> 整又;
typedef stack<整> 整堆;
typedef vector<整> 整向;
typedef vector<整向> 整向向;
typedef vector<整向向> 整向向向;
typedef vector<小> 小向;
typedef vector<小向> 小向向;
typedef vector<字> 字向;
typedef vector<字向> 字向向;
typedef vector<字串> 字串向;
typedef vector<整對> 整對向;
typedef vector<小對> 小對向;
typedef vector<小對向> 小對向向;
typedef vector<整小對> 整小對向;
typedef vector<旗> 旗向;
typedef vector<旗向> 旗向向;

構 邊 { 整 對, 費; };
typedef vector<邊> 圖;

整 大值(整 一, 整 二) { 返 max(一, 二); }
整 小值(整 一, 整 二) { 返 min(一, 二); }

//定 整 無限 = LLONG_MAX;
//定 整 法 = 1000000007;
//定 小 境界 = 1e-9;
//定 小 半円 = acos(-1.0);
//定 整 百 = 100;
//定 整 千 = 1000;
//定 整 萬 = 10000;
//定 整 億 = 100000000;
//定 整 變横[4] = {1, 0, -1, 0};
//定 整 變縦[4] = {0, -1, 0, 1};
定 整 最點 代 8;
整 點數, 邊數;
旗 地圖[最點][最點];
旗 到[最點];

無 入力關數()
{
    輸入(點數) >> 邊數;
    再(邊, 0, 邊數 - 1)
    {
        整 一, 二;
        輸入(一) >> 二;
        地圖[一 - 1][二 - 1] 代 地圖[二 - 1][一 - 1] 代 真;
    }
    再(點, 0, 點數 - 1)
    {
        到[點] 代 偽;
    }
}

整 深優先(整 起點)
{
    旗 到全 代 真;

    再(點, 0, 點數 - 1)
    {
        如(到[點] 是 偽)
        到全 代 偽;
    }

    如(到全)
    {
        返 1;
    }

    整 路數 代 0;

    再(點, 0, 點數 - 1)
    {
        如(地圖[起點][點] 是 偽)
        次;
        如(到[點])
        次;
        到[點] 代 真;
        路數 代 路數 + 深優先(點);
        到[點] 代 偽;
    }

    返 路數;
}

整數 心()
{
    入力關數();
    到[0] 代 真;
    輸出(深優先(0)) << 空行;
    返 0;
}
