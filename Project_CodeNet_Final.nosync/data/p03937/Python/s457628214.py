from collections import defaultdict
from collections import deque
from collections import Counter
import itertools
import math

def readInt():
  return int(input())
def readInts():
  return list(map(int, input().split()))
def readChar():
  return input()
def readChars():
  return input().split()

h,w = readInts()
a = [list(input()) for i in range(h)]
check = [["."]*w for i in range(h)]
check[0][0]="#"

now = (0,0)
goal = (h-1,w-1)

while 1:
  if now==goal and check==a:
    print("Possible")
    break
  s = (now[0],now[1]+1)
  t = (now[0]+1,now[1])
  if s[1]<w and a[s[0]][s[1]]=="#":
    check[s[0]][s[1]]="#"
    now = s
  elif t[0]<h and a[t[0]][t[1]]=="#":
    check[t[0]][t[1]]="#"
    now = t
  else:
    print("Impossible")
    break