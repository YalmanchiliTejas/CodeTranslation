N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()
answer = 0
if N%2 == 0:
    lower = A[:N//2]
    upper = A[N//2:]
    x = 2 * sum(upper) - upper[0]
    y = 2 * sum(lower) - lower[-1]
    answer = x - y
else:
    mid = A[N//2]
    lower = A[:N//2]
    upper = A[N//2 + 1:]
    r1 = 2 * sum(upper) - mid - (2 * sum(lower) - lower[-1])
    r2 = 2 * sum(upper) - upper[0] + mid - 2 * sum(lower)
    answer = max(r1, r2)
print(answer)    
