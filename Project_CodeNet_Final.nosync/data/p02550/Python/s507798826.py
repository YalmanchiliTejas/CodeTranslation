import sys
readline = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
mod = 998244353
INF = 10**18
eps = 10**-7

n,x,m = map(int,readline().split())

if n == 1:
    print(x)
    exit()

if n < 10**7:
    a = [0]*n
    a[0] = x
    for i in range(n-1):
        a[i+1] = a[i]**2%m
    print(sum(a))
    exit()



a = [0]*(m+10)
a[0] = x

for i in range(m+5):
    a[i+1] = a[i]**2%m

idx = [-1]*m

for i in range(m+5):
    if (idx[a[i]] == -1):
        idx[a[i]] = i
    else:
        idxx = idx[a[i]]
        now = i
        break

d = sum(a[idxx:now])
l = now-idxx
ans = sum(a[:idxx])
n -= idxx
ans += d*(n//l)
n = n%l
ans += sum(a[idxx:idxx+n])
print(ans)





