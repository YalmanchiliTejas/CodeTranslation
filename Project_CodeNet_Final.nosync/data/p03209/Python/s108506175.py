N,X=map(int,input().split())
a=[2**(i+2)-3 for i in range(N+1)]
p=[2**(i+1)-1 for i in range(N+1)]
def ans(n,x):
    if n==0:
        return 1
    if x<=1:
        return 0
    elif x<=2**(n+1)-2:
        return ans(n-1,x-1)
    elif x==2**(n+1)-1:
        return p[n-1]+1
    elif x<=2**(n+2)-4:
        return p[n-1]+1+ans(n-1,x+1-2**(n+1))
    else:
        return p[n]
print(ans(N,X))
