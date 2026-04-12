N,X=map(int,input().split())
p=[1]
a=[1]
for i in range(1,1+N):
    b=2*p[i-1]+1
    p.append(b)
    c=2*a[i-1]+3
    a.append(c)

ans=[]
if X==1:
    print(0)
    exit()
def f(n,x):
    #print(n)
    if n==0:
        return 0 if x<=0 else 1
    elif x<=(1+a[n-1]):
        return f(n-1,x-1)
    else:
        return p[n-1]+1+f(n-1,x-2-a[n-1])
print(f(N,X))
