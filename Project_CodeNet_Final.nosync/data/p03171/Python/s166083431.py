import numpy as np

N = int(input())
A = list(map(int, input().split()))

A = np.array(A, dtype = np.int64)
INF = 10 ** 12

dp1 = np.array([-INF] * (N + 1), dtype = np.int64)
dp2 = np.array([+INF] * (N + 1), dtype = np.int64)

if N % 2 == 0:
    dp2[1:] = -A[:]
    # print (dp2)
    for k in range(2, N + 1):
        if k % 2 == 1:
            dp2[k:] = np.minimum(dp1[k - 1:N] - A[k - 1:], dp1[k:] - A[:N - k + 1])
            # print (dp2)
        else:
            # print (dp2[k - 1:N], A[k - 1:], dp2[k:], A[: N - k])
            dp1[k:] = np.maximum(dp2[k - 1:N] + A[k - 1:], dp2[k:] + A[:N - k + 1])
            # print (dp1)
    print (dp1[N])

else:
    dp1[1:] = A[:]
    # print (dp1)
    for k in range(2, N + 1):
        if k % 2 == 0:
            dp2[k:] = np.minimum(dp1[k - 1:N] - A[k - 1:], dp1[k:] - A[:N - k + 1])
            # print (dp2)
        else:
            # print (dp2[k - 1:N], A[k - 1:], dp2[k:], A[: N - k])
            dp1[k:] = np.maximum(dp2[k - 1:N] + A[k - 1:], dp2[k:] + A[:N - k + 1])
            # print (dp1)
    print (dp1[N])
