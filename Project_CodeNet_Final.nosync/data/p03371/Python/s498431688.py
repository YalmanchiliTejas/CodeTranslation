A, B, C, X, Y = map(int,input().split())
AB = 2*C*max(X,Y)
AandB = A*X + B*Y
if X > Y:
    ABandAandB = 2*C*min(X,Y)+(X-Y)*A
else:
    ABandAandB = 2*C*min(X,Y)+(Y-X)*B
print(min(AB,AandB,ABandAandB))