N=int(input())
A=sorted(int(input())for _ in[0]*N)
n=N//2-1
b=A[n+1]
print(2*sum(A[n+2:])-2*sum(A[:n])+b-A[n]-(min(A[n]+A[n+2],2*b)if N%2>0 else 0))