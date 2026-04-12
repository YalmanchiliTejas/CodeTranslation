#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int val;
	int add;
} Node;

Node seg[1 << 20];
int n, q;
char s[300001];

inline void evaluate(int idx)
{
	seg[idx].val += seg[idx].add;
	if (idx < (1 << 19) - 1){
		seg[idx * 2 + 1].add += seg[idx].add;
		seg[idx * 2 + 2].add += seg[idx].add;
	}
	
	seg[idx].add = 0;
}

void update(int k)
{
	seg[k].val = min(seg[k * 2 + 1].val, seg[k * 2 + 2].val);
}

void add(int a, int b, int x, int k = 0, int l = 0, int r = n)
{
	evaluate(k);
	if (r <= a || b <= l) return;
	
	if (a <= l && r <= b){
		seg[k].add += x;
		evaluate(k);
		return;
	}
	
	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);
	update(k);
}

int getMin(int a, int b, int k = 0, int l = 0, int r = n)
{
	evaluate(k);
	if (r <= a || b <= l) return (INT_MAX);
	
	if (a <= l && r <= b){
		evaluate(k);
		return (seg[k].val);
	}
	
	int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
	int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
	update(k);
	
	return (min(left, right));
	
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