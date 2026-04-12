# AOJ 0502: Dice
# Python3 2018.6.29 bal4u

d = { "North":1, "East":2, "West":3, "South":4, "Right":5, "Left":6 }

rot = ((0,1,2,3,4,5,6),(0,2,6,3,4,1,5),(0,4,2,1,6,5,3),(0,3,2,6,1,5,4), \
       (0,5,1,3,4,6,2),(0,1,3,5,2,4,6),(0,1,4,2,5,3,6))

import sys
while True:
	n = int(input())
	if n == 0: break
	dice = [[j for j in range(7)] for i in range(2)]
	ans = 1
	for i in range(n):
		j = d[input().strip()]
		for k in range(1, 7): dice[1-(i&1)][k] = dice[i&1][rot[j][k]]
		ans += dice[1-(i&1)][1]
	print(ans)
