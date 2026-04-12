
N = int(input())
s = input()
s = list(s)
s.append(s[0])
SW01 = [[0, 0],[0, 1],[1, 0],[1, 1]]


for i in range(4):
	SW = []
	SW.append(SW01[i][0])
	SW.append(SW01[i][1])
	for loc in range(1, N + 1):
		if s[loc] == "o":
			SW.append(SW[loc-1]^SW[loc])
		else:
			SW.append(SW[loc - 1] ^ (SW[loc]^1))
	if SW[0] == SW[-2] and SW[1] == SW[-1]:
		SW2 = []
		for i in range(N):
			if SW[i] == 0:
				SW2.append('S')
			else:
				SW2.append('W')
		print("".join(SW2))
		exit()


print(-1)