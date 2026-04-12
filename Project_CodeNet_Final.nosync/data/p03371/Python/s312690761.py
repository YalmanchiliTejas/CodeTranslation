A, B, C, X, Y = list(map(int, input().split()))

a = A*X+B*Y
b = max(X,Y)*C*2
c = min(X,Y)*C*2
if max(X,Y) == X:
    c += (X-Y)*A
else:
    c += (Y-X)*B

print(min(min(a,b),c))