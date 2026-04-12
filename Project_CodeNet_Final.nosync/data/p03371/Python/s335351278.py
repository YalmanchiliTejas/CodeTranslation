# /user/bin/python
# -*- coding: utf-8 -*-
import sys
import math

A,B,C,X,Y = map(int, input().split())
X = float(X)
Y = float(Y)

ans = 0
if A+B > 2*C:
  mn = min(X,Y)
  ans += 2*C*int(mn)
  X -= mn
  Y -= mn

if A > 2*C and X > 0:
  ans += 2*C*math.ceil(X)
  X = 0

if B > 2*C and Y > 0:
  ans += 2*C*math.ceil(Y)
  Y = 0

if X > 0:
  ans += A*math.ceil(X)

if Y > 0:
  ans += B*math.ceil(Y)

print(ans)