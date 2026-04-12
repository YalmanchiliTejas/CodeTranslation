#coding: utf-8
r,g,b = map(int, raw_input().split(' '))
mod = (100 * r + 10 * g + b) % 4

if mod == 0:
	print 'YES'
else:
	print 'NO'