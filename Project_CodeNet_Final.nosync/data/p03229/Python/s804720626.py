N=int(input())
A=[int(input()) for i in range(N)]
A=sorted(A)
b=(N+1)//2
if N%2==0:
  B=A[:b]
  C=A[b:]
  ans=2*(sum(C)-sum(B))-C[0]+B[-1]
  print(ans)
else:
  B=A[:b-1]
  C=A[b-1:]
  ansa=2*(sum(C)-sum(B))-C[0]-C[1]
  B=A[:b]
  C=A[b:]
  ansb=2*(sum(C)-sum(B))+B[-1]+B[-2]
  print(max(ansa,ansb))