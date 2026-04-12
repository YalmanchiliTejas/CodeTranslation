from collections import defaultdict
from collections import deque
from collections import Counter
import math
import itertools

def readInt():
  return int(input())
def readInts():
  return list(map(int, input().split()))
def readChar():
  return input()
def readChars():
  return input().split()

n,x,m = readInts()
an = x
ans = an
moddict = {an:1}
for i in range(2,n+1):
  an = pow(an,2,m)
  if an in moddict:
    break
  else:
    moddict[an]=i
  ans += an
#print(ans)
if an in moddict:
  rep = (n-len(moddict))//(len(moddict)-moddict[an]+1)
  rem = (n-len(moddict))%(len(moddict)-moddict[an]+1)
  #print(rep,rem)
  rep_sum = 0
  boo = 0
  for key in moddict:
    if boo or key==an:
      boo = 1
      rep_sum+=key

  ans += rep_sum*rep
  for i in range(rem):
    ans+=an
    an=pow(an,2,m)


print(ans)