N, X = (int(i) for i in input().split())
t = [1]
p = [1]

for i in range(N):
    t.append(2 * t[i] + 3)
    p.append(2 * p[i] + 1)

def burger(L, E):
    if L == 0:
        return 1
    if E == 1:
        return 0
    elif E <= t[L-1] + 1:
        return(burger(L-1, E-1))
    elif E == t[L-1] + 2:
        return(p[L-1] + 1)
    elif E <= 2 * t[L-1] + 2:
        return(p[L-1] + 1 + burger(L-1, E-2-t[L-1]))
    else:
        return(2 * p[L-1] + 1)

print(burger(N, X))
