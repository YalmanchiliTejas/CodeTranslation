# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	n=int(io())
	hs = list(map(int, io().split()))
	max_h=0
	nn=0
	for i, h in enumerate(hs):
		if h >= max_h:
			nn+=1
			max_h=h
	return nn

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))