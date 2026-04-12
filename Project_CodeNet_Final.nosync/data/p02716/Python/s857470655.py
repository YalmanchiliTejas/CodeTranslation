N = int(input())
A = list(map(int, input().split()))

ans = sum(A[1::2])
dA = []
for a1, a2 in zip(A, A[1:]):
    dA.append(a1 - a2)

max_cum_l = 0
cum_l = 0
L = [0]
for idx_l in range(0, N - 1, 2):
    cum_l += dA[idx_l]
    max_cum_l = max(max_cum_l, cum_l)
    L.append(max_cum_l)
max_cum_r = 0
cum_r = 0
R = [0]
for idx_r in range(N - 2, -1, -2):
    cum_r -= dA[idx_r]
    max_cum_r = max(max_cum_r, cum_r)
    R.append(max_cum_r)
R.reverse()
if N%2:
    ma = -(1<<60)
    for l, r in zip(L, R):
        if ma < l+r:
            ma = l+r
    print(ans + ma)
else:
    print(max(L) + ans)
