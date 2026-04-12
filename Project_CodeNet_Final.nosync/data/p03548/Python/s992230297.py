import sys

X, Y, Z = map(int, input().split())

#n 
for n in range(X):
    if Y + 2*Z + (n - 1) * (Y + Z) > X:
        break;

print (n - 1)