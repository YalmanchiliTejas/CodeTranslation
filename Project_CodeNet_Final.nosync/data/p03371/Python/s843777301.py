A, B, C, X, Y = map(int, input().split())

ans = 10**8

if(X>Y):
    if(A*X+B*Y>Y*C*2+(X-Y)*A):
        ans = (Y*C*2+(X-Y)*A)
    else:
        ans = (A*X+B*Y)
else:
    if(A*X+B*Y>X*C*2+(Y-X)*B):
        ans = (X*C*2+(Y-X)*B)
    else:
        ans = (A*X+B*Y)
    
ans = min(ans, max(X, Y)*C*2)
print(ans)
