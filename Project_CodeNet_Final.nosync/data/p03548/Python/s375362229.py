from sys import stdin
import math
 
x, y, z = stdin.readline().split()
 
print (math.floor(( ( int(x)-int(z) ) / ( int(y) + int(z) ) )))