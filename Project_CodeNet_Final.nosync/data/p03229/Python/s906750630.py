n = int(input())
A = [int(input()) for _ in range(n)]
A.sort()
if n%2==1:
    a = 2*sum(A[n-n//2:]) - sum(A[n-n//2-2:n-n//2]) - 2*sum(A[:n-n//2-2])
    b = -2*sum(A[:n//2]) + sum(A[n//2:n//2+2]) + 2*sum(A[n//2+2:])
    print(max(a,b))
else: print(-2*sum(A[:(n-2)//2])-A[(n-2)//2]+A[(n-2)//2+1]+2*sum(A[(n-2)//2+2:]))