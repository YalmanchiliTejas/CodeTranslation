import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, sX, mod = mapint()

X = sX
s = set()
s.add(X)
s_loop = set()
ans = X
loop = 0
loops = []
i = -1
for i in range(min(10**5*2+10, N-1)):
    X = pow(X, 2, mod)
    if X in s:
        if X in s_loop:
            loops.append(X)
            break
        loop += X
        s_loop.add(X)
        loops.append(X)
    s.add(X)
    ans += X

rest = N-i-2
if rest:
    ans += (rest//len(s_loop))*loop
    amari = rest%len(s_loop)+1
    for i in range(amari):
        ans += loops[i]
    print(ans)
else:
    print(ans)