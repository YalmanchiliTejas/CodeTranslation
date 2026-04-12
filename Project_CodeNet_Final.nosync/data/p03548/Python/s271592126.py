x, y, z = [int(i) for i in input().split()]

count = 0
length = 0
while x >= (length + z):
  count += 1
  length += (y + z)

print(count - 1)