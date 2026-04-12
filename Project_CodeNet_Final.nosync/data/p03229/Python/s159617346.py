n = int(input())
A = sorted([int(input()) for i in range(n)])

if n % 2 == 0:
    ans = (sum(A[n//2+1:])-sum(A[:n//2-1]))*2 + A[n//2] - A[n//2-1]
else:
    ans = max((sum(A[n//2+2:])-sum(A[:n//2]))*2 + A[n//2] + A[n//2+1],
              (sum(A[n//2+1:])-sum(A[:n//2-1]))*2 - A[n//2] - A[n//2-1])

print(ans)
