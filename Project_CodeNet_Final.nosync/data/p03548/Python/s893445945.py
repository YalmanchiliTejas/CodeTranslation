X, Y, Z = list(map(int, input().split()))

A = 1
while A*(Y + Z) + Z <= X:
    A = A + 1

print(A-1)