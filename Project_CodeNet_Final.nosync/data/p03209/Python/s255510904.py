n, x = map(int, input().split())
P = [1]
A = [1]
for i in range(n):
    P.append(P[i] * 2 + 1)
    A.append(A[i] * 2 + 3)

def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    
    elif x <= A[n-1] + 1:
        return f(n-1, x-1)
    
    else:
        return P[n-1] + 1 + f(n-1, x-A[n-1] -2)
    
print(f(n, x))