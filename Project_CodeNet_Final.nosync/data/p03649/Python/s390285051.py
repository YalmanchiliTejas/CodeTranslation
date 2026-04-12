import sys
N = int(input())
As = list(map(int, input().split()))
def f(K):
    c = 0
    for a in As:
        c += (a+K+1)//(N+1)
#    print(K, K-c)
    return c<=K
def f2(K):
    c = 0
    for a in As:
        c += (a+K+1)//(N+1)
#    print(K, K-c)
#    print(K, c)
    return c<=K
for a in As:
    if a>=N:
        break
else:
    print(0)
    sys.exit()
mn, mx = 0, 10**18
idx = mx//2
while mx-mn>1:
    if f(idx):
        mx, idx = idx, (idx+mn)//2
        continue
    mn, idx = idx, (mx+idx)//2
#print(idx+1)
mn = max(1, idx-10**3)
for i in range(mn, mn+10**3+2):
    if f2(i):
        print(i)
        break
