# -*- coding: utf-8 -*-
import sys

x = input()
num = int(''.join(x.split()))
if num % 4 == 0:
    print('YES')
else:
    print('NO')
