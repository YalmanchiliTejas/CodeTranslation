N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

if N % 2 == 0:
    ans = 0
    for i in range(N // 2):
        ans -= 2 * A[i]
    for i in range(N // 2, N):
        ans += 2 * A[i]
    ans += A[N // 2 - 1]
    ans -= A[N // 2]
    print(ans)
else:
    ans1 = 0
    for i in range(N // 2):
        ans1 -= 2 * A[i]
    for i in range(N // 2, N):
        ans1 += 2 * A[i]
    ans1 -= A[N // 2]
    ans1 -= A[N // 2 + 1]

    ans2 = 0
    for i in range(N // 2 + 1):
        ans2 -= 2 * A[i]
    for i in range(N // 2 + 1, N):
        ans2 += 2 * A[i]
    ans2 += A[N // 2]
    ans2 += A[N // 2 - 1]
    print(max(ans1, ans2))
