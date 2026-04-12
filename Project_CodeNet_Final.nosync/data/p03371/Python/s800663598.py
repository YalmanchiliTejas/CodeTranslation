A,B,C,X,Y = map(int,input().split())

ans = 2*max(X,Y)*C
ans = min(ans,A*X+B*Y)
if X>=Y:ans = min(ans,2*Y*C+(X-Y)*A)
else:ans = min(ans,2*X*C+(Y-X)*B)
print(ans)