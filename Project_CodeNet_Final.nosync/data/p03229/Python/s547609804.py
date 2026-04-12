N=int(input())
A=sorted(int(input())for _ in [0]*N)
n=N//2
print(A[n]+2*sum(A[n+1:])-2*sum(A[:n-1])-A[n-1]if N%2==0 else max(A[n]+A[n+1]+2*sum(A[n+2:])-2*sum(A[:n]),2*sum(A[n+1:])-2*sum(A[:n-1])-A[n-1]-A[n]))