# -*- coding: utf-8 -*-
a, b , c= map(int, input().split())

if (a*100 + b*10 + c) %4 == 0:
	result = "YES"
else:
	result = "NO"
print(result)