X, Y, Z = map(int, input().split())

i = 0
px = 0
while px <= X:
    i += 1
    px = i * (Y + Z) + Z

print(i-1)
