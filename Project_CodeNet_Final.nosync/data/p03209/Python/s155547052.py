def f(k,x):
    if(k==0):
        return 1
    assert(x>=1)
    if(x==1):
        return 0
    if(x<l[k-1]+2):
        return f(k-1, x-1)
    elif(x==l[k-1]+2):
        return b[k-1] + 1
    else:
        return b[k-1] + 1 + f(k-1, x-2-l[k-1])

n,x=map(int,input().split())
l = {0: 1}
b = {0: 1}
for i in range(1,n+1):
    l[i] = 2*l[i-1]+3
    b[i] = 2*b[i-1]+1

ans = f(n,x)
print(ans)