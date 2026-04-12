A,B,C,X,Y = map(int,input().split())
if A+B <= 2*C:
    ans = A*X+B*Y
elif (A <= 2*C and X>=Y) or (B <= 2*C and X <= Y):
    minAB = min(X,Y)
    ans = 2*C*minAB+(X-minAB)*A+(Y-minAB)*B
else:
    ans = 2*C*max(X,Y)
print(ans)