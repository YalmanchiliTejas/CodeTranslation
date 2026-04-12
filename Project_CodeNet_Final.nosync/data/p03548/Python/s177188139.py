import math

x, y, z = map(int, input().split(" "))

ans = math.floor((x - z) / (y + z))

print(ans)
