N=int(input())
A=sorted(int(input())for _ in [0]*N)
n=N//2;m=n+1
print(2*sum(A[n+1:])-2*sum(A[:n-1])+A[n]-A[n-1]-(min(A[n-1]+A[n+1],2*A[n])if N%2>0 else 0))