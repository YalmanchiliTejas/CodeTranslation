x,y,z = map(int, input().split())
len_chair = x - z
print(len_chair // (y + z))