
A,B,C,X,Y = map(int, input().split(" "))

price = min(A+B, C*2)*min(X, Y)

if X > Y:
    if C*2 < A:
        price += (X-Y)*(C*2)
    else:
        price += (X-Y)*A
elif X < Y:
    if C*2 < B:
        price += (Y-X)*(C*2)
    else:
        price += (Y-X)*B

print(price)
