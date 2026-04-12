N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

ans = A[len(A) - 1] - A[0]
small = 0
large = len(A) - 1
while (True):

    if large - small == 1:
        break
    elif large - small == 2:
        ans += max(A[large] - A[large - 1], A[small + 1] - A[small])
        break
    ans += A[large - 1] - A[small] + A[large] - A[small + 1]
    small += 1
    large -= 1

print(ans)
