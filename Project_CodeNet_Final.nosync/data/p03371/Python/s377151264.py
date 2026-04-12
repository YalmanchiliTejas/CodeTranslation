A, B, C, X, Y = map(int, input().split())
price = 0
P = []
s = 0
t = 0
u = 0
if A + B <= 2*C:
    price = A*X + B*Y
else:
    sa = abs(X - Y)
    price = C*2*(min(X, Y)-sa)
    XX = X - (min(X, Y)-sa)
    YY = Y - (min(X, Y)-sa)
    dai = max(XX, YY)
    syou = min(XX, YY)

    for i in range(dai+1):
        u = i*2
        if syou>=i:
            s = XX - i
            t = YY - i
        else:
            if X >= Y:
                s = XX - i
                t = 0
            else:
                s = 0
                t = YY - i
        P.append(A*s + B*t + C*u)
    price += min(P)

print(price)