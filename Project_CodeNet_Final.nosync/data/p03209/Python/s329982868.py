N,K=map(int,input().split())
L=[1]
P=[1]
BG=[0]
for i in range(1,N+1):
  L.append(L[i-1]*2+3)
  P.append(P[i-1]*2+1)
def f(x,y):
  if x==0:
    if y==0:
      return 0
    if y==1:
      return 1
  elif y<=1:
    return 0
  elif 1<y<=L[x-1]+1:
    return f(x-1,y-1)
  elif L[x-1]+1<y<L[x]:
    return P[x-1]+1+f(x-1,y-2-L[x-1])
  elif y==L[x]:
    return P[x]
print(f(N,K))