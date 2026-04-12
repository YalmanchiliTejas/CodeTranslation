import sys
import math
sys.setrecursionlimit(int(1e6))
dprint = print
#def dprint(*args):
#   pass

x = list(map(int, input().split()))[0]
if x >= 30:
    print('Yes')
else:
    print('No')
