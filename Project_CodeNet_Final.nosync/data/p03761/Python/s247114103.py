N=int(input())
ds=[]
for _ in range(N):
  d={}
  for s in input():d[s]=d.get(s,0)+1
  ds+=[d]
r=ds[0]
for d in ds:
  for k,v in r.items():
    r[k]=min(v,d.get(k,0))
ans=''
for k in sorted(r.keys()):
  ans+=k*r[k]
print(ans)