def bg(n,x):##nバーガーのx番目のパティの数
    if n==0:return 1
    l = wid[n-1]
    if x==1:return 0
    if 1<x<=l+1:
        return bg(n-1,x-1)
    if x==l+2:
        return pat[n-1]+1
    if l+2<x<=2*l+2:
        return pat[n-1]+1 + bg(n-1,x-l-2)
    if x==2*l+3 :
        return pat[n]

wid = [1]*51
for i in range(1,51):
    wid[i] = 2*wid[i-1]+3
pat = [1]*51
for i in range(1,51):
    pat[i] = pat[i-1]*2+1
n,x = map(int,input().split())
print(bg(n,x))
