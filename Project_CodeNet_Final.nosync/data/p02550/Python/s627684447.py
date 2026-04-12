n,x,m = map(int,input().split())
a = []
a.append(0)
a.append(x)
isBreak = False
for i in range(1,n):
  #tmp = (a[i]**2)%m
  tmp = (a[i]%m)*(a[i]%m)
  tmp = tmp%m
  if tmp==0:
    break
  if tmp in a:
    isBreak = True
    break
  a.append(tmp)
#print(a)
if isBreak:
  i = 1
  while a[i]!=tmp:
    i+=1
  kurikaeshi = len(a) - i
  goukei = sum(a[i:])
  #print(goukei)
  tmp=(n-(len(a)-1))
  #print(tmp//kurikaeshi)
  a.append(tmp//kurikaeshi * goukei)
  #print(a)
  tmp = tmp%kurikaeshi
  if tmp!=0:
    t = sum(a[i:i+tmp])
    a.append(t)
print(sum(a))