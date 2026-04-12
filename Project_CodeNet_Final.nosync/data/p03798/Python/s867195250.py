import sys
n=int(input())
s=input()
S=[]
for i in range(n):
  if s[i]=="o":
    S.append(1)
  else:
    S.append(-1)
A=[1,1]
for i in range(1,n-1):
  A.append(S[i]*A[-2]*A[-1])
if S[-1]==A[-2]*A[-1]*A[0]:
  if S[0]==A[-1]*A[0]*A[1]:
    for i in range(n):
      if A[i]==1:
        print("S",end="")
      else:
        print("W",end="")
      if i==n-1:
        print()
        sys.exit()
A=[1,-1]
for i in range(1,n-1):
  A.append(S[i]*A[-2]*A[-1])
if S[-1]==A[-2]*A[-1]*A[0]:
  if S[0]==A[-1]*A[0]*A[1]:
    for i in range(n):
      if A[i]==1:
        print("S",end="")
      else:
        print("W",end="")
      if i==n-1:
        print()
        sys.exit()
A=[-1,1]
for i in range(1,n-1):
  A.append(S[i]*A[-2]*A[-1])
if S[-1]==A[-2]*A[-1]*A[0]:
  if S[0]==A[-1]*A[0]*A[1]:
    for i in range(n):
      if A[i]==1:
        print("S",end="")
      else:
        print("W",end="")
      if i==n-1:
        print()
        sys.exit()
A=[-1,-1]
for i in range(1,n-1):
  A.append(S[i]*A[-2]*A[-1])
if S[-1]==A[-2]*A[-1]*A[0]:
  if S[0]==A[-1]*A[0]*A[1]:
    for i in range(n):
      if A[i]==1:
        print("S",end="")
      else:
        print("W",end="")
      if i==n-1:
        print()
        sys.exit()
print(-1)