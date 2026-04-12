# coding: utf-8

def North(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[3]
	new_dice[1] = dice[0]
	new_dice[2] = dice[2]
	new_dice[3] = dice[5]
	new_dice[4] = dice[4]
	new_dice[5] = dice[1]
	return new_dice

def East(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[4]
	new_dice[1] = dice[1]
	new_dice[2] = dice[0]
	new_dice[3] = dice[3]
	new_dice[4] = dice[5]
	new_dice[5] = dice[2]
	return new_dice

def West(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[2] #3
	new_dice[1] = dice[1] #5
	new_dice[2] = dice[5] #6
	new_dice[3] = dice[3] #2
	new_dice[4] = dice[0] #1
	new_dice[5] = dice[4] #4
	return new_dice

def South(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[1] #5
	new_dice[1] = dice[5] #6
	new_dice[2] = dice[2] #3
	new_dice[3] = dice[0] #1
	new_dice[4] = dice[4] #4
	new_dice[5] = dice[3] #2
	return new_dice

def Right(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[0] #1
	new_dice[1] = dice[4] #4
	new_dice[2] = dice[1] #5
	new_dice[3] = dice[2] #3
	new_dice[4] = dice[3] #2
	new_dice[5] = dice[5] #6
	return new_dice

def Left(dice):
	new_dice = [0,0,0,0,0,0]
	new_dice[0] = dice[0] #1
	new_dice[1] = dice[2] #3
	new_dice[2] = dice[3] #2
	new_dice[3] = dice[4] #4
	new_dice[4] = dice[1] #5
	new_dice[5] = dice[5] #6
	return new_dice

while True:
	n = int(raw_input())
	if n == 0:
		break
	dice = [1,5,3,2,4,6] # ??? ??? ??± ??? ?\? ??? ??????
	sum = 1
	for i in range(n):
		instruct = raw_input()
		if instruct[0] == "N":
			dice = North(dice)
		elif instruct[0] == "E":
			dice = East(dice)
		elif instruct[0] == "S":
			dice = South(dice)
		elif instruct[0] == "W":
			dice = West(dice)
		elif instruct[0] == "R":
			dice = Right(dice)
		elif instruct[0] == "L":
			dice = Left(dice)
		#print("** {:} **".format(dice[0]))
		sum += dice[0]
	print(sum)