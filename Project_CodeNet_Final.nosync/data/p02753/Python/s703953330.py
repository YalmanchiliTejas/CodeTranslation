# -*- coding: utf-8 -*-
import sys


S = input()

a = S.count('A')
b = S.count('B')
if a==0 or b==0:
    print('No')
else:
    print('Yes')