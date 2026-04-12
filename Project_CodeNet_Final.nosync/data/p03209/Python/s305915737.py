n,x=map(int,input().split())
k=[1]*51
d=[1]*51
for i in range(1,51):
    k[i]=2*k[i-1]+3
    d[i]=2*d[i-1]+1
def f(n,x):
    if n==0:
        return 1
    if x==1:
        return 0
    if x<2+k[n-1]:
        return f(n-1,x-1)
    if x==2+k[n-1]:
        return d[n-1]+1
    if x<2+2*k[n-1]:
        return d[n-1]+1+f(n-1,x-2-k[n-1])
    else:
        return 2*d[n-1]+1
print(f(n,x))