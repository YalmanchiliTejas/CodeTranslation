#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
#define lson rt << 1
#define rson rt << 1 | 1
const int N = 100000 + 10;
struct node
{
    int l, r;
    int w; //  w维护值  lazy懒标记
} tree[(N << 2) + 10];
inline int read()
{
    int num = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch))
    {
        num = (num << 3) + (num << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -num : num;
}

//快速写
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
void build(int rt, int l, int r) //建树初始化
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].w = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    tree[rt].w = tree[lson].w + tree[rson].w; //合并父节点
}
int query(int rt, int ql, int qr) //区间查询 单点查询时ql==qr
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l >= ql && r <= qr)
    {
        return tree[rt].w; //查询维护值w
    }
    int mid = (l + r) >> 1;
    int ans = 0;
    if (ql <= mid)
        ans += query(lson, ql, qr);
    if (qr > mid)
        ans += query(rson, ql, qr);
    return ans;
}

void updata(int rt, int x, int val) //单点更新  x更新点 val更新值
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l == r)
    {
        tree[rt].w += val;
        return;
    }
    int mid = (l + r) >> 1;

    if (x <= mid)
        updata(lson, x, val);
    else if (x > mid)
        updata(rson, x, val);
    tree[rt].w = tree[lson].w + tree[rson].w; //合并父节点
}

int x[100000 + 10];
int lsh[100000 + 10];
int n;
int fin(int k, int size, int pos)
{
    int l = 1;
    int r = pos - 1;
    int sum = query(1, l, r);
    if (sum == 0)
        return -1;
    else
    {
        int ans = r;
        while (l <r)
        {
            if (l + 1 == r)
                break;
            int mid = (l + r) >> 1;
            if (query(1, mid, r) >= 1)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if (query(1, r, r))
            return r;
        return l;
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        x[i] = read();
        lsh[i] = x[i];
    }
    sort(lsh + 1, lsh + 1 + n);
    int size = unique(lsh + 1, lsh + 1 + n) - (lsh + 1);
    build(1, 1, size);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(lsh + 1, lsh + 1 + size, x[i]) - lsh;
        int res = fin(x[i], size, pos);
        if (res != -1)
            updata(1, res, -1);
        updata(1, pos, 1);
    }
    write(query(1, 1, size));
    return 0;
}