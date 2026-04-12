import math

A, B, C, X, Y = map(int, input().split())

cost = []
cost.append(A*X + B*Y)

for i in range(2*min(X,Y), 2*max(X,Y)+1):
    cost.append(C*i + max(0, math.ceil(X-i/2)*A) + max(0, math.ceil(Y-i/2)*B))

print(min(cost))