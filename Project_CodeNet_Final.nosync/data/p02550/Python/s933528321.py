N,X,M=map(int,input().split())
d={}
x=X
A=[]
init=0
loop=0
S=[0]
while x not in d:
    d[x]=1
    A.append(x)
    S.append(S[-1]+A[-1])
    x=x*x%M

init=A.index(x)
loop=len(A)-init

if N<=init+loop:
    print(S[N])
else:
    l=(N-init)//loop
    r=(N-init)%loop
    print((S[-1]-S[init])*l+S[init+r])

