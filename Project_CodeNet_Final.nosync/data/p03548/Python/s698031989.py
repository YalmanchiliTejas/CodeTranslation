x, y, z = map(int, input().split())
i = 0
base=z
while base + y + z <= x:
    base += y + z
    i += 1
print(i)