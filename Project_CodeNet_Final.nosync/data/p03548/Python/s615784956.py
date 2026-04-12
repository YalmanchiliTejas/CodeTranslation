import sys
x, y, z = list(map(int, sys.stdin.readline().strip().split(" ")))

num = 0
x -= z
while x >= (y+z):
    x -= (y+z)
    num += 1
print(str(num))
