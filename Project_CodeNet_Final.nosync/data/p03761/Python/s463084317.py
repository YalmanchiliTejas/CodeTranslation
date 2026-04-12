n=int(input())
from collections import *
f=lambda:Counter(input())
c=f()
for i in range(1,n): c&=f()
print(''.join(sorted(c.elements())))