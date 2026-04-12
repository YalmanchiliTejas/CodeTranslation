import math
x,y,z = (int(i) for i in input().split()) 
ans = math.floor((x-z)/(y+z))
print(ans)