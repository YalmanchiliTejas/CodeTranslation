X, Y, Z = map(int, input().split())

L = X - Z
if L <= 0:
    print(0)
print(L // (Y+Z))