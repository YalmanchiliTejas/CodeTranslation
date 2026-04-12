n,q=map(int,raw_input().split())
exist=[False]*(n+2)
exist[1]=True
cup=range(n+2)
now=1
exist[cup[now-1]]=True
exist[cup[now+1]]=True
for i in xrange(q):
    a,b=map(int,raw_input().split())
    if now==a:now=b
    elif now==b:now=a
    tmp=cup[a]
    cup[a]=cup[b]
    cup[b]=tmp
    exist[cup[now-1]]=True
    exist[cup[now+1]]=True
ans=0
for i in xrange(1,n+1):
    if exist[i]:ans+=1
print ans
