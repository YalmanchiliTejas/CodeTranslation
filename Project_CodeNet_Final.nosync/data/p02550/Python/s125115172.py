def pow_k(x,n,p=10**9+7):
    if n==0:
        return 1
    K=1
    while n>1:
        if n%2!=0:
            K=(K*x)%p
        x=(x*x)%p
        n//=2
    return (K*x)%p

N,X,M=map(int,input().split())

sumA=[0]
res=0
MOD=[0]*(10**5+10)
x=X
A,B=[],[]
for i in range(1,N+1):
    if MOD[x]==1:
        point=x
        B=[]
        res=0
        while 1:
            res+=x
            B.append(res)
            x=(x*x)%M
            if x==point:
                break
    else:
        MOD[x]=1
        res+=x
        A.append(res)
        x=(x*x)%M        
    if B:
        break
if not B:
    print(A[-1])
else:
    C=[0]+B
    N-=len(A)
    print(A[-1]+B[-1]*(N//len(B))+(C[N%len(B)]))