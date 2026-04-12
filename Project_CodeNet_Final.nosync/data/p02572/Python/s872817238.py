def resolve():
    N = int(input())
    A = [int(i) for i in input().split(maxsplit=N)]
    presum = [0 for _ in range(N + 1)]
    for i in range(N):
        presum[i + 1] = presum[i] + A[i]
    sumA = 0
    for i in range(1, N):
        sumA += (A[i] * (presum[i])) % (10**9 + 7)
    print(sumA % (10**9 + 7))


resolve()
