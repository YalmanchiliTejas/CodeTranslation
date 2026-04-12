# ABC078 B - ISU

# Y*[人数]+Z*[人数]+1 <=X
# 3*q+1*q+1<=13
# Y*q+(Z+1)*q<=X
## Y*q+Z*(q+1)<=X
## q<=(X-Z)/(Y+Z) 
# q<=(X)/(Y+Z+1)

import math
x,y,z = map(int,input().split())
t = (x-z)/(y+z)
print(math.floor(t))


