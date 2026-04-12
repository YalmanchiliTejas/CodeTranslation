import math
n = int(input())
y = (n-n%15)/15if n >= 15 else 0
print(math.floor(800*n - y*200))