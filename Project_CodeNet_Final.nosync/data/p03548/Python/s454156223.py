# B
# 2020/03/03 9:33-
x, y, z = map(int, input().split())

n = 0
while (y+z)*n + z <= x:
    n += 1
    
print(n-1)