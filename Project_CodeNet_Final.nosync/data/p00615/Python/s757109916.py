# AOJ 1029: Traffic Analysis
# Python3 2018.7.6 bal4u

import sys
from sys import stdin
input = stdin.readline

while True:
	n, m = map(int, input().split())
	if n == 0 and m == 0: break
	if n > 0: a = list(map(int, input().split()))
	if m > 0: b = list(map(int, input().split()))
	ans = i = j = 0
	s, t = 0, -1
	while i < n or j < m:
		if i < n:
			if s == a[i]: i += 1
			if i < n: t = a[i]
		if j < m:
			if s == b[j]: j += 1
			if j < m and (t < 0 or b[j] < t): t = b[j]
		if t >= 0:
			if i < n and t == a[i]: i += 1
			if j < m and t == b[j]: j += 1
			ans = max(ans, t-s)
			s, t = t, -1
	if t >= 0: ans = max(ans, t-s)
	print(ans)
