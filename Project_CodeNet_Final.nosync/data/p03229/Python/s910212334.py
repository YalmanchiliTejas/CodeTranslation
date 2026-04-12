n=int(input())
A=[]
for i in range(n):
  A.append(int(input()))
A=sorted(A)
if n%2==0:
  B=[]
  C=[]
  for i in range(n//2):
    B.append(A[i])
    C.append(A[i+n//2])
  ans=0
  ans=ans+C[0]-B[0]
  for i in range(1,n//2):
    ans=ans+C[i]*2-B[i-1]-B[i]
  print(ans)
else:
  B=[]
  C=[]
  for i in range((n-1)//2):
    B.append(A[i])
    C.append(A[i+(n+1)//2])
  B.append(A[(n-1)//2])
  ans1=2*sum(C)-2*sum(B)+B[-1]+B[-2]
  B=[]
  C=[]
  for i in range((n-1)//2):
    B.append(A[i])
    C.append(A[i+(n-1)//2])
  C.append(A[-1])
  ans2=2*sum(C)-2*sum(B)-C[0]-C[1]
  print(max(ans1,ans2))