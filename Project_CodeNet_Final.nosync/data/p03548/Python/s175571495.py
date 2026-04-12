X, Y, Z = map(int, input().split())

a = X // (Y+Z)
if (Y+Z) * a + Z <= X:
    print(a)
else:
    print(a-1)
