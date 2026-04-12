import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, X, mod = mapint()
first = set()
second = set()
in_loop = []
ans = 0
for i in range(min(10**5*2, N)):
    if X in first:
        if X in second:
            break
        in_loop.append(X)
        second.add(X)
    first.add(X)
    ans += X
    X = pow(X, 2, mod)
else:
    print(ans)
    exit()

loop_len = len(in_loop)
rest = N-len(first)-len(in_loop)
ans += (rest//loop_len)*sum(in_loop)
amari = rest%loop_len
for i in range(amari):
    ans += in_loop[i]
print(ans)