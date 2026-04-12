import sys
input=sys.stdin.readline

n,x,m=map(int,input().split())

l=[x]
check=[False]*m
check[x]=True
a=x

while True:
    a=a**2%m
    if check[a]:
        last=a
        break
    l.append(a)
    check[a]=True

for i in range(len(l)):
    if l[i]==last:
        index=i

start=l[0:index]
cycle=l[index:]

if n<len(start):
    ans=sum(start[0:n])
else:
    ans=sum(start)
    cn=(n-len(start))//len(cycle)
    cq=(n-len(start))%len(cycle)
    ans+=sum(cycle)*cn
    ans+=sum(cycle[0:cq])

print(ans)