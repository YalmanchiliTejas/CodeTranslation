n, x = map(int, input().split())
 
P = [0] * (n + 1)
P[0] = 1
for i in range(1, n + 1):
    P[i] = P[i - 1] * 2 + 1

A = [0] * (n + 1)
A[0] = 1
for i in range(1, n + 1):
    A[i] = A[i - 1] * 2 + 3

#print(P)
#print(A)
 
def dfs(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    elif x <= 1 + A[n - 1]:
        return dfs(n - 1, x - 1)
    elif x == 1 + A[n - 1] + 1:
        return P[n - 1] + 1
    elif 1 + A[n - 1] + 1 < x < 1 + A[n - 1] + 1 + A[n - 1] + 1:
        return P[n - 1] + 1 + dfs(n - 1, x - 1 - A[n - 1] - 1)
    elif x >= 1 + A[n - 1] + 1 + A[n - 1] + 1:
        return P[n - 1] + 1 + P[n - 1]
    
print(dfs(n, x))    