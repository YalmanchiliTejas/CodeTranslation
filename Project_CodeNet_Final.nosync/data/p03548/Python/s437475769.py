

import numpy as np

x,y,z=map(int,input().split())
x-=z
print(x//(y+z))