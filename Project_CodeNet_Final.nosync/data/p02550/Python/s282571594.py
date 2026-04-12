N,X,M=map(int,input().split())
l=[-1]*M
a=0
t=X
l[X]=0
if t**2%M==t:
    print(N*t)
    exit()
for i in range(1,M+1):
    t=t**2%M
    if l[t]==-1:
        l[t]=i
    else:
        s,g=l[t],i
        break
if N<=s+1:
    t=X
    a=X
    for i in range(N-1):
        t=t**2%M
        a+=t
    print(a)
else:
    t=X
    a=0
    if s!=0:
        a=X
    for i in range(s-1):
        t=t**2%M
        a+=t
    t2=t
    c=0
    for i in range(g-s):
        t=t**2%M
        c+=t
    if s==0:
        for i in range(N%(g-s)):
            a+=t2
            t2=t2**2%M
    else:
        for i in range((N-s)%(g-s)):
            t2=t2**2%M
            a+=t2
    a+=c*((N-s)//(g-s))
    print(a)