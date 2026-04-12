import sys
import os
if sys.platform=="darwin":
   base = os.path.dirname(os.path.abspath(__file__))
   name = os.path.normpath(os.path.join(base, '../Documents/input.txt'))
   #print(name)
   sys.stdin = open(name)

h,w = map(int, input().split())
l = [str(input()) for _ in range(h)]

#print(l)
ans = 0
for i in range(h):
   ans = ans + l[i].count(".")

#print(ans)

if ans == (h-1)*(w-1):
   print("Possible")
else:
   print("Impossible")
