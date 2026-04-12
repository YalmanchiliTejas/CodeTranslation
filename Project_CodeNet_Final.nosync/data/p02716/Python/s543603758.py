import numpy as np

N = int(input())
A = list(map(int, input().split()))


A = np.array([0, 0] + A)

cum_0 = A[::2].cumsum()
cum_1 = A[1::2].cumsum()


ans = -float("inf")

if N % 2:
    cum_10 = cum_1.copy()
    cum_10 -= cum_0[1:]
    cum_01 = cum_0[:-1].copy()
    cum_01 -= cum_1

    cum_max_01 = np.zeros_like(cum_01)
    for i in range(1, len(cum_max_01)):
        cum_max_01[i] = max(cum_max_01[i - 1], cum_01[i])

    ans = (cum_max_01 + cum_10).max()
    ans += cum_0[-1]
else:
    for i in range(0, N // 2 + 1):
        tmp = cum_0[i] + (cum_1[-1] - cum_1[i])
        ans = max(ans, tmp)
print(ans)

pass
