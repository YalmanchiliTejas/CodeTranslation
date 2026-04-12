n,x,m=map(int,input().split())
visited=set()
visited_l=[]
loop=set()
loop_l=[]
visited.add(x)
visited_l.append(x)
xc=x
for i in range(m):
    xc=(xc**2)%m
    if xc in visited and not(xc in loop):
        loop.add(xc)
        loop_l.append(xc)
    elif xc in visited and xc in loop:
        break
    else:
        visited.add(xc)
        visited_l.append(xc)
s=len(visited_l)
t=len(loop_l)



if n<=s:
    

    print(sum(visited_l[:n]))
elif n<=s+t:
    print(sum(visited_l)+sum(loop_l[:n-s-t]))

else:
    ans=sum(visited)
    n=n-s
    ans+=(sum(loop_l)*(n//t))
    ans+=sum(loop_l[:n%t])
    print(ans)
    