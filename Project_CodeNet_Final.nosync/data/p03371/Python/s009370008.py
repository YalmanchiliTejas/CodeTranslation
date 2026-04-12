A,B,C,X,Y = map(int,input().split())
a = min(X,Y)
b = max(X,Y)
if A+B>=2*C:
    ans = a*2*C
    if X>=Y:
        ans += (X-Y)*min(A,2*C)
    else:
        ans += (Y-X)*min(B,2*C)
else:
    ans = A*X+B*Y
print(ans)