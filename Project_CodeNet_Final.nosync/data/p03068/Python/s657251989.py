# -*- coding: utf-8 -*-

import sys
input = sys.stdin.readline

def io_generator():
	return input()

#+++++++++++++++++++
	
def main(io):
	n=int(io())
	s=io()[:n]
	k=int(io())
	cc=s[k-1]
	ll=lambda c:c if c==cc else '*'

	return ''.join([ll(c) for c in list(s)])

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))