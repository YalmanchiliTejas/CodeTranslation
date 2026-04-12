A, B, C, X, Y = map(int, input().split())

cost = min(A+B, 2*C)*min(X, Y)

if X<Y:
    cost+=min(B, 2*C)*(Y-X)
    print(cost)
elif Y<X:
    cost+=min(A, 2*C)*(X-Y)
    print(cost)
else:
    print(cost)