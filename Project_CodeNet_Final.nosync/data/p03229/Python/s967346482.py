N=int(input())
A=[int(input()) for _ in range(N)]

A.sort(reverse=True)
if len(A)%2==0:
  print(A[len(A)//2-1]-A[len(A)//2]+2*sum(A[:len(A)//2-1])-2*sum(A[len(A)//2+1:]))
else:
  tmp1=-A[len(A)//2]-A[len(A)//2+1]+2*sum(A[:len(A)//2])-2*sum(A[len(A)//2+2:])
  tmp2=A[len(A)//2-1]+A[len(A)//2]+2*sum(A[:len(A)//2-1])-2*sum(A[len(A)//2+1:])
  print(tmp1 if tmp1>tmp2 else tmp2)