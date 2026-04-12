N,X = map(int,input().split())
l = [1]*(N+1)
p = [1]*(N+1)
for i in range(N):
    l[i+1] = 2*l[i]+3
    p[i+1] = 2*p[i]+1
def f(n,x):
    if n==0:return 1
    if x==1:return 0
    if x<= l[n-1]+1:return f(n-1,x-1)
    if x== l[n-1]+2:return 1+p[n-1]
    return 1+p[n-1]+f(n-1,x-2-l[n-1])
print(f(N,X))