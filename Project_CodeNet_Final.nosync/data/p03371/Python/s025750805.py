A, B, C, X, Y = map(int, input().split())

print(min(A+B, C*2) * min(X,Y) + (X - min(X,Y)) * min(A, C*2) + (Y - min(X,Y)) * min(B, C*2))