x, y, z = map(int, input().split())
space = x - y - 2*z
a = space // (y+z)
print(a+1)