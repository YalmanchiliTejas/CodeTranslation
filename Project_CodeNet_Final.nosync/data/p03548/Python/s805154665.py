import math

a, b, c=map(int, input().split(" "))

i = math.floor(a / b)

while a / (b * i + c * (i + 1)) < 1:
  i -= 1

print(i)