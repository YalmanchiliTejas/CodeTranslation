#include <bits/stdc++.h>
 
using namespace std;
 
int segMin[1 << 20], segAdd[1 << 20];
int n, q;
char s[300001];
 
void add(int a, int b, int x, int k = 0, int l = 0, int r = n)
{
    if (r <= a || b <= l) return;
     
    if (a <= l && r <= b){
        segAdd[k] += x;
        while (k){
            k = (k - 1) / 2;
            segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
        }
        return;
    }
     
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
}
 
int getMin(int a, int b, int k = 0, int l = 0, int r = n)
{
    if (r <= a || b <= l) return (INT_MAX);
     
    if (a <= l && r <= b) return (segMin[k] + segAdd[k]);
     
    int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
    int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
     
    return (min(left, right) + segAdd[k]);
     
}
 
void fix(set<int> *a, set<int> *b, char before, int x)
{
    a->erase(x);
    b->insert(x);
     
    int base = before == '(' ? -1 : 1;
    s[x] = before == '(' ? ')' : '(';
     
    add(x, n, 2 * base);
     
    int l = 0, r = x;
    int p;
     
    while (l != r){
        int mid = l + r >> 1;
        p = *b->lower_bound(mid);
        if (getMin(p, n) >= 2 * base) r = mid;
        else l = mid + 1;
    }
     
    p = *b->lower_bound(l);
    add(p, n, -2 * base);
    b->erase(p);
    a->insert(p);
    s[p] = before;
     
    printf("%d\n", p + 1);
}
 
int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", s);
     
    set<int> lf, rg;
     
    for (int i = 0; s[i]; i++){
        if (s[i] == '('){
            add(i, n, 1);
            lf.insert(i);
        }
        else {
            add(i, n, -1);
            rg.insert(i);
        }
    }
     
    for (int i = 0; i < q; i++){
        int x;
        scanf("%d", &x); x--;
         
        if (s[x] == '(') fix(&lf, &rg, '(', x);
        else fix(&rg, &lf, ')', x);
    }
     
    return (0);
}