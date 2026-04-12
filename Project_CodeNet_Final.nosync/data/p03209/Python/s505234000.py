N,X = list(map(int,input().split()))
a = [1]
p = [1]
def f(n,x):
    if x == 1:
        if n == 0:return 1
        else:return 0
    elif 1 < x and x < 2+a[n-1]:
        return f(n-1,x-1)
    elif 2+a[n-1] == x:
        return 1 + p[n-1]
    elif 2+a[n-1] < x and x < 3+2*a[n-1]:
        return p[n-1]+1+f(n-1,x-2-a[n-1])
    else:
        return 2*p[n-1]+1


for i in range(1,N+1):
    a.append(2*a[i-1]+3)
    p.append(2*p[i-1]+1)

print(f(N,X))