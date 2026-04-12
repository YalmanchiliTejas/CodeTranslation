s = input()

for i in range(1,3):
	if s[i] != s[0]:
		print("Yes")
		exit()
print("No")
