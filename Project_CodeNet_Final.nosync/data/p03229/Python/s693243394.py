N = int(input())
A = [int(input()) for k in range(N)]
A = sorted(A)
k = N//2
if N%2 == 1:
    print(max(-2*sum(A[:k])+sum(A[k:k+2])+2*sum(A[k+2:]),-2*sum(A[:k-1])-sum(A[k-1:k+1])+2*sum(A[k+1:])))
else:
    print(-2*sum(A[:k-1])-A[k-1]+A[k]+2*sum(A[k+1:]))
