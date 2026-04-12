# /usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math



def main(x,y,z):
	ret = 0
	while(1):
		if ret*(y+z)+z > x:
			return ret-1
		else:
			ret += 1


if __name__ == "__main__":
	X,Y,Z = map(int, input().split())
	print(main(X,Y,Z))