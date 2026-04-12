N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
    
def myfunc(L, X):
    if L==0:
        return 1 if X>0 else 0
    elif X==1:
        return 0
    elif 1<X and X<=a[L-1]+1:
        return myfunc(L-1, X-1)
    elif X==a[L-1]+2:
        return p[L-1]+1
    else:
        return p[L-1]+1+myfunc(L-1, X-a[L-1]-2)

print(myfunc(N, X))