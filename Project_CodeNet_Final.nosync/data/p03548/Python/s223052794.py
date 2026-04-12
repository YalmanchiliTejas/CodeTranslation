X, Y, Z = map(int, input().split())
tmp = X//(Y+Z)
if X - tmp*(Y+Z) < Z:
    print(tmp - 1)
else:
    print(tmp)
