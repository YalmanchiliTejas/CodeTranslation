x,y,z = map(int,input().split())
no_tip = (y+z)*(x//(y+z))
space = 1 if x-no_tip < z else 0
print(x//(y+z) - space)