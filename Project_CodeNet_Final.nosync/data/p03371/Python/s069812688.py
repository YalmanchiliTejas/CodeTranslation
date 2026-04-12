A,B,C,Y,X = map(int, input().split())
m1 = A * Y + B * X
m2 = C * 2 * min(X,Y) + A * max(Y-X, 0) + B * max(X-Y,0)
m3 = C * 2 * max(X,Y)
print(min(m1,m2,m3))