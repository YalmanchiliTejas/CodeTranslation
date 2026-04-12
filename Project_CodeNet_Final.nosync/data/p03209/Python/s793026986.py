def search(x, l):
    if L == 0: n = 0
        
    elif x == L[l]: n = p[l]
    elif x == 1: n = 0
    elif 1 < x < L[l-1]: n = search(x-1, l-1)
    elif x == L[l-1]+1: n = p[l-1]
    elif x == L[l-1]+2: n = p[l-1]+1
    else: n = search(x-(2+L[l-1]), l-1) + 1 + p[l-1]
    
    return n
        

N, X = map(int, input().split())

L = [1] * (N+1)
p = [1] * (N+1)

for i in range(1, N+1):
    L[i] = 2 * L[i-1] + 3
    p[i] = 2 * p[i-1] + 1

print(search(X, N))