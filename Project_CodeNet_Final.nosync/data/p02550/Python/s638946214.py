n,x,m=map(int,input().split())
mod=m

lst=[]
ans=0
gg=0
while True:
    gg+=1
    if x==0:
        print(sum(lst))
        exit()

    elif x in lst:
        break

    else:
        lst.append(x)
        x=(x**2)%mod
    
    if gg==n:
        print(sum(lst))
        exit()


log=[]
for i,v in enumerate(lst):
    if v==x:
        log.append(i)


ans+=sum(lst)
n-=len(lst)

newlst=lst[log[0]:]
ans+=sum(newlst)*(n//len(newlst))
if n%len(newlst)!=0:
  ans+=sum(newlst[:n%len(newlst)])

print(ans)