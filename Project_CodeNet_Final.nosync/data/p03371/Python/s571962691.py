A,B,C,X,Y = map(int,input().split())
ans = A*X+B*Y
if X < Y:
    ans = min(ans,2*C*X+(Y-X)*B)
elif X > Y:
    ans = min(ans,2*C*Y+(X-Y)*A)
else:
    ans = min(ans,2*C*X)
ans = min(ans,2*C*max(X,Y))
print(ans)