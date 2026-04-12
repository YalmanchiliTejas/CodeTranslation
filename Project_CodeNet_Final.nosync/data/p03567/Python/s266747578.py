s = input()

ok = False
for i in range(len(s)-1):
	if s[i:i+2] == "AC":
		print("Yes")
		exit()

print("No")