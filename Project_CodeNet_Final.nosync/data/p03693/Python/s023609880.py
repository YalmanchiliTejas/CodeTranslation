#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from collections import deque

inputline = list(map(int, sys.stdin.readline().split()))

rgb = inputline[0] * 100 + inputline[1] * 10 + inputline[2]

if rgb%4==0:
	print('YES')
else:
	print('NO')