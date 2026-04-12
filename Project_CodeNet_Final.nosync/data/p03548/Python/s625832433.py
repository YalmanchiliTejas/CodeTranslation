x, y, z = [int(i) for i in input().split()]
t = 0
for i in range(1, 114514):
    l = y * i + 2*z + z * (i-1)
    if l <= x:
        t = i
    else:
        break
print(t)
