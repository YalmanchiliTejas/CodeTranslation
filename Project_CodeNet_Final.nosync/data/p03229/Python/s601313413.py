N = int(input())
A = [int(input()) for _ in range(N)]
A.sort(reverse=True)

if N % 2 == 0:
    res = 0
    for i in range(N // 2 - 1):
       res += A[i] * 2
    res += A[N // 2 - 1]
    res -= A[N // 2]
    for i in range(N // 2 + 1, N):
        res -= A[i] * 2
    print(res)
else:
    res1 = 0
    for i in range(N // 2 - 1):
        res1 += A[i] * 2
    res1 += A[N // 2 - 1] + A[N // 2]
    for i in range(N // 2 + 1, N):
        res1 -= A[i] * 2

    res2 = 0
    for i in range(N // 2):
        res2 += A[i] * 2
    res2 -= A[N // 2] + A[N // 2 + 1]
    for i in range(N // 2 + 2, N):
        res2 -= A[i] * 2
    print(max(res1, res2))
