p = [1]*51
t = [1]*51
def f(n,x):
    if n==0:
        return 1
    if x==1:
        return 0
    if x==t[n]:
        return p[n]
    if x==p[n]:
        return p[n-1]+1
    if x<p[n]:
        return f(n-1,x-1)
    return p[n-1]+f(n-1,x-p[n])+1

for i in range(1,51):
    p[i] = p[i-1]*2+1
    t[i] = t[i-1]*2+3
n,x = map(int,input().split())    
print(f(n,x))
