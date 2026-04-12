x, y, z = map(int, input().split())
num = 0
x -= z
while x >= 0:
    x -= y + z
    num += 1

print(num-1)