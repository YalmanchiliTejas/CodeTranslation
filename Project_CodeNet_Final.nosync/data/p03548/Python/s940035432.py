x, y, z = map(int, input().split())
i = 0
while y*i + z*(i+1) <= x:
    i += 1
i -= 1
print(i)
