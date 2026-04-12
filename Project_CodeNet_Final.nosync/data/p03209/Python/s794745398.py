N, X = map(int, input().split())

l, p = [1], [1]
for i in range(N):
    l.append( l[i]*2 + 3 )
    p.append( p[i]*2 + 1 )

def patty(n, x):
    if n == 0:
        if x > 0 : return 1
        else : return 0
    elif x <= 1 + l[n-1]:
        return patty(n-1,x-1)
    else:
        return p[n-1] + 1 + patty(n-1, x-2-l[n-1])

print(patty(N,X))
