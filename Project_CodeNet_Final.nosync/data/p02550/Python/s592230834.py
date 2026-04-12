N,_X,M=map(int,input().split())
X=_X

s=set()

while True:
    if X==0:
        print(sum(s))
        exit()
    if X in s:
        break
    else:
        s.add(X)
        X=X**2%M
    
loop=set()
while True:
    if X in loop:
        break
    else:
        loop.add(X)
        X=X**2%M

bef_loop=[]
X=_X
while True:
    if  X in loop:
        break
    else:
        bef_loop.append(X)
        X=X**2%M

if N<=len(bef_loop):
    print(sum(bef_loop[:N]))
else:
    ans=sum(bef_loop)
    R=N-len(bef_loop)

    ans+=R//len(loop)*sum(loop)
    r=R%len(loop)

    X=_X
    for _ in range(len(bef_loop)):
        X=X**2%M
    for _ in range(r):
        ans+=X
        X=X**2%M
    print(ans)

