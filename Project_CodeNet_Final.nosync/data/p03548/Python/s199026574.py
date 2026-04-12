x, y, z = map(int, input().split())
i = 0
while x - y*i - z*(i+1) >= 0:
    i += 1
print(i-1)
