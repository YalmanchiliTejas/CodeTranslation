#!/usr/bin/env python
# -*- coding: utf-8 -*-
X = int(input())
def f(n):
  if (n == 3)or(n == 5)or(n == 7):
    return "YES"
  else:
    return "NO"
    
print("{}".format(f(X)))