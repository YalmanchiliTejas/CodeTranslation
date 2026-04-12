x,y,z = map(int,input().split())
space = 2 * z + y
man = 1
while x >= space:
  space += y + z
  man += 1
print(man-1)