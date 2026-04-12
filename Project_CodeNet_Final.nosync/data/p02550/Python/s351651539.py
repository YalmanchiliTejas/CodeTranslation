import sys
n,x,m=map(int,input().split())
a=[0]*(m+2)
cnt=[0]*(m+2)
a[1],f=x,x
cnt[f]=1
if x==0:
  print(0)
  sys.exit()
for i in range(2,m+1):
  f=f*f%m
  a[i]=f
  if cnt[f]==0:
    cnt[f]=1
  else:
    break
ind=a[1:].index(f)+1
ans=sum(a[:ind])+sum(a[ind:i])*((n-ind+1)//(i-ind))
p=(n-ind+1)%(i-ind)
ans+=sum(a[ind:ind+p])
print(ans)