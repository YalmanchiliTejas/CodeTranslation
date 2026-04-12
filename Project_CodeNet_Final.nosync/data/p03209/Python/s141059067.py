#!/mnt/c/Users/moiki/bash/env/bin/python
N, X = map(int, input().split())

    
L = [1]
P = [1]

for i in range(0, N+1):
    L.append( L[i] * 2 + 3)
    P.append( P[i] * 2 + 1)

        
    
def calc_pan(n,x):
    # c = judge(n,x)
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + L[n-1]:
        return calc_pan(n-1, x-1)
    else:
        return P[n-1] + 1  + calc_pan(n-1, x - 2 - L[n-1])

sum = calc_pan(N, X)
print(sum)



