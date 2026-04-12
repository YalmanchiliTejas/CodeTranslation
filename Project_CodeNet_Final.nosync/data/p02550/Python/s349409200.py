N,x,M=map(int,input().split())
k=x
L=list()
c=dict()
for i in range(M):
  if i==N:
    print(sum(L))
    exit()
  if x==0:
    print(sum(L))
    exit()
  L.append(x)
  x=(x*x)%M
  if x in c:
    q=x
    break
  c[x]=1
moto=sum(L)
N-=len(L)
for i in range(len(L)):
  if L[i]==q:
    roop=list(L[i:])
L=roop
a=len(L)
if N%a==0:
  print(moto+(sum(L)*(N//a)))
else:
  s=N//a
  t=N%a
  ans=sum(L)*s
  ans+=sum(roop[:t])
  print(moto+ans)