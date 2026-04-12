N,X,M=map(int, input().split())

p=[0]*(M+2)
sum=[0]*(M+2)
p[X]=1
sum[1]=X
f=0
for i in range(2,N+1):
    X=(X**2)%M  
    if p[X]!=0:
        j=p[X]
        f=i
        break
    else:
        sum[i]=X+sum[i-1]
        p[X]+=i

if f==0:
    print(sum[N])
else:
    d,mod=divmod(N-j+1,i-j)
    print(d*(sum[i-1]-sum[j-1])+sum[j+mod-1])