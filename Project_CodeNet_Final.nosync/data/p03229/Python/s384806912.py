n=int(input())
A=sorted([int(input()) for i in range(n)])
if n%2==0:
  ans=-2*sum(A[:n//2-1])-A[n//2-1]+A[n//2]+2*sum(A[n//2+1:])
  print(ans)
else:
  ans=-2*sum(A[:n//2])+A[n//2]+A[n//2+1]+2*sum(A[n//2+2:])
  ans=max(ans,-2*sum(A[:n//2-1])-A[n//2-1]-A[n//2]+2*sum(A[n//2+1:]))
  print(ans)