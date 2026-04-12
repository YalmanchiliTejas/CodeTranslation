#!/usr/bin/env python3 pypy

import sys

sys.setrecursionlimit(10 ** 6)


def main():
	s = input()
	if s == "AAA" or s == "BBB":
		print("No")
	else:
		print("Yes")

main()