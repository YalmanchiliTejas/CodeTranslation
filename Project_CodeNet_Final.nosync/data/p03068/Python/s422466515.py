#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
	n = int(input())
	s = input()
	k = int(input())
	tmp=''
	for i in range(n):
		if i == k-1:
			tmp = s[i]	
	ans = ''
	for c in s:
		if c != tmp:
			ans+='*'
		else:
			ans+=c
	print(ans)

if __name__ == '__main__':
	import sys
	sys.exit(main())

