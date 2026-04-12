
N,X = map(int,input().split())

a,p = [1],[1]
for i in range(N):
    a.append(a[i]*2 + 3)
    p.append(p[i]*2 + 1)

def calc(n,x):
    if n==0:
        if x <= 0:
            return 0
        else:
            return 1
    elif x <= 1 + a[n-1]:
        return calc(n-1,x-1)
    else:
        return p[n-1] + 1 + calc(n-1,x-2-a[n-1])

print(calc(N,X))