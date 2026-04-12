A,B,C,X,Y = map(int,input().split())
if A+B>=2*C:
    ans = 2*C*min(X,Y)
    if X>=Y:
        ans += (X-Y)*min(A,2*C)
    else:
        ans += (Y-X)*min(B,2*C)
else:
    ans = (A+B)*min(X,Y)
    if X>=Y:
        ans += (X-Y)*A
    else:
        ans += (Y-X)*B
print(ans)