a = [1]
p = [1]
N,X = map(int,input().split())
for i in range(N):
    a.append(2*a[i]+3)
    p.append(2*p[i]+1)
def f(n,x):
    if n == 0:
        return 0 if x <= 0 else 1
    if x <= 1:
        return 0
    elif x <= a[n-1]+1:
        return f(n-1,x-1)
    else:
        return f(n-1,x-2-a[n-1])+p[n-1]+1
print(f(N,X))