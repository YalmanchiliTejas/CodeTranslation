X, Y, Z = map(int, input().split())

S = int(X / (Y + Z))
T = X % (Y + Z)

if T < Z:
    S -= 1

print(S)