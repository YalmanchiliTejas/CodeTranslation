n,x=map(int,input().split())
a=[1]
p=[1]
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
#print(a)

def f(N, X): # X <= 0 や X > a_N を許容し解説本文から簡略化
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= 1 + a[N-1]:
        return f(N-1, X-1)
    else:
        return p[N-1] + 1 + f(N-1, X-2-a[N-1])

print(f(n, x))