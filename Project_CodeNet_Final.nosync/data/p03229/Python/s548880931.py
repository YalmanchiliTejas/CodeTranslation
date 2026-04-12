N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))

A.sort()
ans = 0
if N % 2 == 0:
    for i in range(N):
        if i < N // 2 - 1:
            ans -= A[i] * 2
        elif i == N // 2 - 1:
            ans -= A[i]
        elif i == N // 2:
            ans += A[i]
        else:
            ans += A[i] * 2
else:
    ans = 0
    for i in range(N):
        if i < N // 2:
            ans -= A[i] * 2
        elif N // 2 <= i <= N // 2 + 1:
            ans += A[i]
        else:
            ans += A[i] * 2
    ans2 = 0
    for i in range(N):
        if i < N // 2 - 1:
            ans2 -= A[i] * 2
        elif N // 2 - 1 <= i <= N // 2:
            ans2 -= A[i]
        else:
            ans2 += A[i] * 2
    # print(ans, ans2)
    ans = max(ans, ans2)
print(ans)