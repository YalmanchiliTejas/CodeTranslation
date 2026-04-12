N,K=map(int,input().split())
a=[1]
p=[1]
for i in range(N):
  a.append(a[i]*2+3)
  p.append(p[i]*2+1)
def find(N,K):
  if N==0:
    return 0 if K<=0 else 1
  elif K<=a[N-1]+1:
    return find(N-1,K-1)
  else:
    return p[N-1]+1+find(N-1,K-2-a[N-1])
print(find(N,K))