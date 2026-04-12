a,b,c = input()
k = [a,b,c]
import collections
c = collections.Counter(k)
if len(c) == 2:
  print("Yes")
else:
  print("No")