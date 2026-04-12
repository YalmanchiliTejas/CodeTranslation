N = int(input())
A = [int(input()) for i in range(N)]

A.sort()
left = A[0]
right = A[N - 1]
ans = right - left
for i in range((N - 2) // 2):
    if i % 2 == 0:
        ans += right - A[1 + i]
        ans += A[N - 2 - i] - left
        right = A[1 + i]
        left = A[N - 2 - i]
    else:
        ans += left - A[1 + i]
        ans += A[N - 2 - i] - right
        left = A[1 + i]
        right = A[N - 2 - i]

if N % 2 == 1:
    ans += max(abs(right - A[N // 2]), abs(left - A[N // 2]))

print(ans)