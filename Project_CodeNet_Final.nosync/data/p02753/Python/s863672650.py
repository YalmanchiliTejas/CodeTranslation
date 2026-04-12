s = input()
d = {"A":0,"B":0}
for i in s:
	d[i] += 1
if (d["A"] == 2 and d["B"] == 1) or (d["A"] == 1 and d["B"] == 2):
	print("Yes")
else:
	print("No")