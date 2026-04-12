X, Y, Z = map(int, input().split())
d,m = divmod(X - Z * 2, Y+Z)
print(d + (1 if Y <= m else 0))