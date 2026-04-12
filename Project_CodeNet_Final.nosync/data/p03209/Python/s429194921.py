N,X=map(int,input().split())
L=[0]*(N+1)
t=1
L[0]=t
for i in range(1,N+1):
    t=2*t+3
    L[i]=t
M=[0]*(N+1)
s=1
for i in range(1,N+1):
    s=2*s+1
    M[i]=s
a=X
ans=0
for i in range(N-1,0,-1):
    t=L[i]
    s=M[i]
    if a==1:
        a-=1
        break
    elif 2<=a<=t+1:
        a-=1
    elif a==t+2:
        a-=t+2
        ans+=s+1
        break
    elif t+3<=a<=2*t+2:
        ans+=s+1
        a=a-(t+2)
    elif a==2*t+3:
        a-=2*t+3
        ans+=2*s+1
        break
#print('g',i,ans,a,X)
if 0<=a<=4:
    ans+=max(a-1,0)
else:
    ans+=3
print(ans)