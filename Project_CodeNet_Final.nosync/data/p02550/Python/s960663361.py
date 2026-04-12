n,x,m=map(int,input().split())
ans=x
a=[x]
d={}
d[x]=1
if n==1:
  print(ans)
else:
  for i in range(2,n+1):
    tmp=a[-1]**2%m
    if d.get(tmp,0)==0:
      a.append(tmp)
      d[tmp]=1
      ans+=tmp
    else:
      t=a.index(tmp)
      if len(a)-t>=n-i+1:
        ans+=sum(a[t:t+n-i+1])
        break
      else:
        t=a.index(tmp)
        tmp_a=(n-i+1)//(len(a)-t)
        tmp_b=(n-i+1)-(len(a)-t)*tmp_a
        ans+=sum(a[t:])*tmp_a+sum(a[t:t+tmp_b])
        break
  print(ans)