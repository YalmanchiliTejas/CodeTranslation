# -*- coding: utf-8 -*-

while(True):
	N,A,B,C,X = map(int, input().split())
	if (N==0&A==0&B==0&C==0&X==0):break
	y = list(int(i) for i in input().split())  
	frame = 0
	reel = 0
	while(True):
		if(frame ==10001):
			frame = -1
			break
		if y[reel] == X:
			reel += 1

		if reel == N:
			break
		X = (A * X + B)%C
		frame += 1

	print(frame)

