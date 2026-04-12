import math

il = list(map(int, input().split()))

x = il[0]
y = il[1]
z = il[2]

tmp = (x - z) / (y + z)

ans = math.floor(tmp)
print(ans)
