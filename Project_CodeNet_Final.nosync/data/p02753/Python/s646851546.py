X = input()
a, b = 0, 0
for i in range(len(X)):
	if X[i] == "A":
		a += 1
	else:
		b += 1
if a == 3 or b == 3:
	print("No")
else:
	print("Yes")
