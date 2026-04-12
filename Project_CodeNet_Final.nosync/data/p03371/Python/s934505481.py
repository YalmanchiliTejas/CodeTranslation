A,B,C,X,Y = map(int,input().split())

p = A+B
q = 2*C
z = min(X,Y)
r = abs(X-Y)
if p <= q :
    ans = A*X+B*Y
else :
    ans = q*z
    if z == Y :
        if A <= 2*C :
            ans += A*r
        else :
            ans += q*r
    else :
        if B <= 2*C :
            ans += B*r
        else :
            ans += q*r
print(ans)
