X, Y, Z = map(int, input().split())
c = 0
l = Z
while l < X:
    if l + Y + Z <= X:
        l += Y + Z
        c += 1
    else:
        break
print(c)