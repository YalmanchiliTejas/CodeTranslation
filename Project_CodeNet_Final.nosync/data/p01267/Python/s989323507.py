while True:
  N,A,B,C,X=map(int,input().split())
  if N==0 and A==0 and B==0 and C==0 and X==0:
    break
  Y=list(map(int,input().split()))
  count=0
  real=0
  j=0
  while True:
    if X==Y[j]:
      count+=1
      j+=1
    if count==int(len(Y)):
      break
    if real>=10000:
      real=-1
      break
    X=(A*X+B)%C
    real+=1
  print(real)
