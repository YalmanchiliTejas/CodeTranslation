# -*- coding: utf-8 -*-
import sys
import copy
import collections
from bisect import bisect_left
	
def main():
	H, W = map(int, input().split())
	chk = "." * W
	A = []
	for _ in range(H):
		tmp = input()
		if tmp != chk:
			A.append(list(tmp))
		else:
			H -= 1
			
	del_list = []
	for i in range(W):
		del_ok = True
		for j in range(H):
			if "." != A[j][i]:
				del_ok = False
				break
		if del_ok == True:
			del_list.append(i)
			
	ans = []
	line = ""
	for i in range(H):
		line = ""
		for j in range(W):
			if j in del_list:
				continue
			line += A[i][j]
		print(line)
	
if __name__ == "__main__":
	main()
