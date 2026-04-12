A, B, C, X, Y = map(int, input().split())
if A+B < 2*C:
    print(A*X+B*Y)
else:
    low = min(X,Y)
    high = max(X,Y)
    if C*(high-low)*2<=A*(X-low)+B*(Y-low):
        print(C*high*2)
    else:
        print(C*low*2+A*(X-low)+B*(Y-low))