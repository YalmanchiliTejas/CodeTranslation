A,B,C,X,Y = [int(x) for x in input().split()]
ans = 10**15
ans = min(ans,X*A+Y*B)
if(X<Y):
    ans = min(ans,2*X*C+(Y-X)*B)
else:
    ans = min(ans,2*Y*C+(X-Y)*A)
ans = min(ans,2*max(X,Y)*C)
print(ans)
