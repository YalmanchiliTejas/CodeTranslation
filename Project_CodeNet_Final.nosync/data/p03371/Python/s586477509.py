A, B, C, X, Y = map(int, input().split())

money = [A*X+B*Y, 2*C*max(X,Y)]
n = min(X, Y)
x, y = X - n, Y - n
money.append(A*x+B*y+2*C*n)
money.append(A*n+B*n+2*C*(max(X,Y)-n))
print(min(money))