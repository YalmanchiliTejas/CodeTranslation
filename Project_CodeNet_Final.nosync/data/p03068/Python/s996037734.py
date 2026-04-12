#!/usr/bin/python
# coding: UTF-8

import re

len = int(input())
src = input()
t = int(input())
pt = "[^"+src[t-1]+"]"
print(re.sub(pt,"*",src))
