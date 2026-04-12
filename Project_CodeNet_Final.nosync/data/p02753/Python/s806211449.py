S = input()
flag = 0
for i in range(2):
	if S[i] == S[i+1]:
		pass
	else:
		flag = flag +1

if flag >= 1:
	print("Yes")
else:
	print("No")