#!/usr/bin/env python
# -*- coding: utf-8 -*-

s = input()

resultA = s.find("AAA")
resultB = s.find("BBB")

if resultA == 0:
    print("No")
elif resultB == 0:
    print("No")
else:
    print("Yes")

