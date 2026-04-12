A,B,C,X,Y = map(int,input().split())
if 2*C<=A+B:
    if X<=Y:
        ans = 2*C*X
        ans += (Y-X)*min(B,2*C)
    else:
        ans = 2*C*Y
        ans += (X-Y)*min(A,2*C)
else:
    if X<=Y:
        ans = (A+B)*X
        ans += (Y-X)*B
    else:
        ans = (A+B)*Y
        ans += (X-Y)*A
print(ans)    