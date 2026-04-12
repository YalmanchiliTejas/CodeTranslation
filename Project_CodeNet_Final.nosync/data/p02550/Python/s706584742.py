N, X, M = map(int, input().split())
if X == 0:
    print(0)
    exit()
U = [0] * (M + 10)
U[X] = 1
S = [0] * (M + 10)
S[1] = X
v = X
l = r = 0  # [l,r) で巡回
cycle_sum = 0
for i in range(2, M + 1):
    v = (v * v) % M
    if U[v]:
        l = U[v]
        r = i
        cycle_sum = S[i - 1] + v - S[l]
        break
    U[v] = i
    S[i] = S[i - 1] + v
if N <= l:
    print(S[N])
    exit()

ans = S[l - 1]
N -= l - 1
d, m = divmod(N, r - l)
ans += d * cycle_sum
ans += S[l + m - 1] - S[l - 1]
print(ans)
