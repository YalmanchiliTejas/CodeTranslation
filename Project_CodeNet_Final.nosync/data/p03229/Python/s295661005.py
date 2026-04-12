N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

if N % 2 == 0:
    ans = sum(A[N//2:]) + sum(A[N//2 + 1:]) - sum(A[:N//2]) - sum(A[:N//2-1])
else:

    ans = sum(A[N//2:]) + sum(A[N//2+2:]) - 2 * sum(A[:N//2])
    
    ans = max(ans, 2 * sum(A[N//2+1:]) - sum(A[:N//2+1]) - sum(A[:N//2-1]))
    
print(ans)
       