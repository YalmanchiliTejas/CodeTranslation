A,B,C,X,Y = map(int, input().split())

C = min(2 * C, A + B)
A = min(A, C)
B = min(B, C)

Z = min(X,Y)

print( Z * C + (X-Z) * A + (Y-Z) * B)