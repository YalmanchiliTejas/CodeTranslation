N,X = list(map(int,input().split()))

f=[1]
p=[1]

for n in range(N):
    f.append(2*f[n]+3)
    p.append(2*p[n]+1)

def get_p(N,X):
    if N == 0:
        if X <= 0:
            return 0
        else:
            return 1
    if X == 1:
        return 0
    elif X > 1 and X <= f[N-1] + 1:
        return get_p(N-1,X-1)
    elif X == f[N-1] + 2:
        return p[N-1]+1
    elif X > f[N-1] + 2 and X <= 2*f[N-1] + 1: 
        return p[N-1] + 1 + get_p(N-1,X-(f[N-1]+2))
    else:
        return p[N]
    
print(get_p(N,X))