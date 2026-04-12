import sys
import math
x, y, z = map(int, input().split())
tmp=1
while ((tmp*y+(tmp+1)*z)<=x):
    tmp += 1
print(tmp-1)