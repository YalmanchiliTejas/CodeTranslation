#!/usr/bin/env python3
# 


i = int(input())
if i > 7:
  print("NO")
elif i % 7 == 0:
  print("YES")
elif i > 5:
  print("NO")
elif i % 5 == 0:
  print("YES")
elif i % 3 == 0:
  print("YES")
else:
  print("NO")