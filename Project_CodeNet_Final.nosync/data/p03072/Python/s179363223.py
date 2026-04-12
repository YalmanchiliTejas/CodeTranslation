N=int(input())
h=list(map(int,input().split()))
t=[]
g=0
for i in range(N):
  t.append(h[i])
  a=max(t)
  if a==t[i]:
    g+=1
print(g)
    
  