A, B, C, X, Y = map(int, input().split())
D = {X:A, Y:B}

print(min(A*X+B*Y, 2*C*min(X, Y) + D[max(X, Y)]*(max(X, Y) - min(X, Y)), 2*C*max(X, Y)))