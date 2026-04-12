# -*- coding: utf-8 -*-
#AGC002A
import sys

#n= int(input())
tmp = input().split()
h,w = list(map(lambda a: int(a), tmp))


map = [[0 for i in range(w+2)] for j in range(h+2)]

for i in range(0,h):
	hoge = input()
	for j in range(0,w):
		map[i+1][j+1]=hoge[j]

for i in range(1,h+1):
#	print(i)
	for j in range(1,w+1):
		if(map[i][j]=="#"):
			if(((map[i+1][j]=="#")and(map[i][j+1]=="#")) or ((map[i+1][j]==".")and(map[i][j+1]=="."))):
#				print("hoge {} {}".format(i,j))
				if(i!=h or j!=w):
					print("Impossible")
					sys.exit()
			if(((map[i-1][j]=="#")and(map[i][j-1]=="#")) or ((map[i-1][j]==".")and(map[i][j-1]=="."))):
#				print("hoga {} {}".format(i,j))
				if(i!=1 or j!=1):
					print("Impossible")
					sys.exit()
print("Possible")

#print(map)