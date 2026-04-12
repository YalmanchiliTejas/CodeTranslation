#!/usr/bin/env python3
s = list(input())
ans = "Yes"
if len(set(s)) == 1:
  ans = "No" 
print(ans)