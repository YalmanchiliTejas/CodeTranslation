import sys
X,Y,Z = map(int,input().split())

if not (1 <= X <= 10 ** 5 and 1 <= Y <= 10 ** 5 and 1 <= Z <= 10 ** 5):
    sys.exit()

if not (Y + 2*Z <= X):
    sys.exit()

max = 0
for I in range(int(X/(Y+Z))+1):
    if X - (Y * I + Z * (I + 1)) >= 0:
        max = I
print(max)