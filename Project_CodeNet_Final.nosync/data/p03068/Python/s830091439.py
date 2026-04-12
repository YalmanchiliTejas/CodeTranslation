# /usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math


n = int(input())
s = str(input())
k = int(input())
ans = ""
for c in s:
  if c == s[k-1]:
    ans += c
  else:
    ans += "*"
print(ans)