import copy
N=str(input())
K=int(input())
m=len(N)
def con(n,r):
  if r==0:
    return 1
  else:
    return (n/r)*con(n-1,r-1)
S=0
for i in range(1,m):
  S=S+(9**K)*con(i-1,K-1)
if K==1:
  S=S+int(N[0])
  print(int(S))
if K==2:
  S=S+9*(m-1)*(int(N[0])-1)
  for i in range(1,m):
    for i1 in range(1,10):
      N1=(int(N[0]))*(10**(m-1))+i1*10**(m-i-1)
      if int(N)>=N1:
        S=S+1
  print(int(S))
if K==3:
  S=S+(int(N[0])-1)*(9**2)*con(m-1,K-1)
  for i in range(1,m-1):
    for j in range(i+1,m):
      for i1 in range(1,10):
        for j1 in range(1,10):
          N1=(int(N[0]))*(10**(m-1))+i1*10**(m-i-1)+j1*10**(m-j-1)
          if int(N)>=N1:
            S=S+1
  print(int(S))