N,X=map(int,input().split())
a,p=[1],[1]
for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
def burger(L,x):
    if L == 0:
        return 0 if x == 0 else 1
    if x <= 1:
        return 0
    if x <a[L-1]+2:
        return burger(L-1,x-1)
    if x == a[L-1]+2:
        return p[L-1]+1
    if x < a[L]:
        return p[L-1]+1+burger(L-1,x-a[L-1]-2)
    if x == a[L]:
        return p[L]
print(burger(N,X))