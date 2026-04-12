n,x=map(int,input().split())
b=[0]*(n+1)
p=[0]*(n+1)
s=[0]*(n+1)
p[0]=1
s[0]=1
for i in range(1,n+1):
    b[i]=2+b[i-1]*2
    p[i]=1+p[i-1]*2
    s[i]=b[i]+p[i]
count=0
for i in range(n):
    i=n-1-i
    if x==0:
        break
    x-=1
    if x>=s[i]:
        x-=s[i]
        count+=p[i]
        if x==0:
            break
        x-=1
        count+=1
        if x>=s[i]:
            x-=s[i]
            count+=p[i]
            break
print(count)