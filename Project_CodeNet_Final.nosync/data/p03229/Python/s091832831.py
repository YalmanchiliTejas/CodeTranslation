def solve():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    if N%2==0:
        ans = (sum(A[N//2:])-sum(A[:N//2]))*2-A[N//2]+A[(N-2)//2]
    else:
        ans = (sum(A[(N+1)//2:])-sum(A[:(N-1)//2]))*2 + max(A[(N-1)//2]-A[(N+1)//2], A[(N-3)//2]-A[(N-1)//2])
    return ans
print(solve())