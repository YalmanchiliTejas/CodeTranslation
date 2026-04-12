n,s = map(int,input().split())
a = list(map(int,input().split()))
mod = 998244353
rui = []
now = 0
pl = []
for i in range(n):
    now += a[i]
    rui.append(now)
l = [[0 for i in range(s)] for i in range(n)]
ans = 0
for i in range(n):
    if a[i] < s:
        l[i][a[i]] += i+1
        l[i][a[i]] %= mod
    elif a[i] == s:
        ans += i*(n-i-1)
        ans += n
        ans %= mod
    for j in range(s):
        if i > 0:
            if l[i-1][j] > 0:
                if j+a[i] < s:
                    l[i][j+a[i]] += l[i-1][j]
                    l[i][j+a[i]] %= mod
                elif j+a[i] == s:
                    ans += l[i-1][j]*(n-i)
                    ans %= mod
                l[i][j] += l[i-1][j]
                l[i][j] %= mod
print(ans)