import collections
n,x,m=map(int,input().split())
if n==1 or x==0:
  print(x)
  exit()
start,end,loopcnt=0,0,0
a={x:0}
wk=x
for i in range(1,m):
  wk=(wk*wk)%m
  if not wk in a:
    a[wk]=i
  else:
    start=a[wk]
    end=i
    break
a=sorted(a.items(),key=lambda x:x[1])
koteiindex=min(n,start)
koteiwa=0
for i in range(koteiindex):
  koteiwa+=a[i][0]
loopcnt=(n-koteiindex)//(end-start)
loopindex=start-1+(n-koteiindex)%(end-start)
loopwa=0
amariwa=0
for i in range(start,end):
  if i<=loopindex:
    amariwa+=a[i][0]
  loopwa+=a[i][0]
ans=koteiwa+loopwa*loopcnt+amariwa
print(ans)
