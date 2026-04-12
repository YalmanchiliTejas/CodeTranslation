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

def f(n,x):
    a=s[n-1]
    if n==0:
        return 1
    elif x==1:
        return 0
    elif x<=a+1:
        return f(n-1,x-1)
    elif x==a+2:
        return p[n-1]+1
    elif x<=2*a+2:
        return f(n-1,x-2-a)+p[n-1]+1
    else:
        return 2*p[n-1]+1
print(f(n,x))