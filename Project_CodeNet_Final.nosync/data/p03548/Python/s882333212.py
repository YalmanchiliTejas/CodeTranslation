X, Y, Z = map(int, input().split())
a, b = divmod(X, Y+Z)
if Z > b:
    a -= 1
print(a)
