
H,W= map(int,raw_input().split())

M = []
for i in range(H):
	M.append(raw_input())
	
flag_list_H = []
for i in range(H):
	if '#' in M[i]:
		flag_list_H.append(True)
	else:
		flag_list_H.append(False)

flag_list_W = []
for i in range(W):
	flag = False
	for j in range(H):
		if M[j][i]=='#':
			flag=True
	flag_list_W.append(flag)

for i in range(H):
	if flag_list_H[i]:
		answer = ""
		for j in range(W):
			if flag_list_W[j]:
				answer+=M[i][j]
		print answer