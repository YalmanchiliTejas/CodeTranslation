def resolve():
    N = int(input())
    A = list(map(int, input().split()))

    ans = 1
    for i in range(1, N):
        now = A[i]
        if (max(A[:i + 1]) <= now):
            ans += 1

    print(ans)


resolve()