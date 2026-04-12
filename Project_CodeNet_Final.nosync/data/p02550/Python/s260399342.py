import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, X, mod = mapint()
doubling = [[i*i%mod for i in range(mod)]]
accu = [doubling[0][:]]

for i in range(40):
    tmp1 = [None]*mod
    tmp2 = [None]*mod
    for j in range(mod):
        tmp1[j] = doubling[-1][doubling[-1][j]]
        tmp2[j] = accu[-1][doubling[-1][j]] + accu[-1][j]
    doubling.append(tmp1)
    accu.append(tmp2)
now = X
ans = X
for i in range(40):
    if (N-1)>>i&1:
        ans += accu[i][now]
        now = doubling[i][now]
print(ans)