A,B,C,X,Y = map(int,input().split())
if X<=Y:
    ans = X*min(A+B,2*C)
    ans += (Y-X)*min(B,2*C)
else:
    ans = Y*min(A+B,2*C)
    ans += (X-Y)*min(A,2*C)
print(ans)