# -*- coding: utf-8 -*-
import re

n = int(input())
s = input()
k = int(input())

c = s[k-1]
out = re.sub('[^{}]'.format(c), "*", s)

print(out)
