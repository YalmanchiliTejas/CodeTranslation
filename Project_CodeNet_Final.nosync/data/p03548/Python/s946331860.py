x, y, z = map(int, input().split())
f_1 = y+z*2
rest_space = x-f_1
print(rest_space//(y+z) + 1)
