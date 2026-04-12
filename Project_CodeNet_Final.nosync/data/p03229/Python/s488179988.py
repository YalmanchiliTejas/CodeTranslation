N=int(input())
A=[int(input()) for i in range(N)]
A.sort()
if N&1:
  print(max(2*(sum(A[N//2+1:])-sum(A[:N//2+1]))+A[N//2]+A[N//2-1],2*(sum(A[N//2:])-sum(A[:N//2]))-A[N//2+1]-A[N//2]))
else:
  print(2*(sum(A[N//2:])-sum(A[:N//2]))-A[N//2]+A[N//2-1])