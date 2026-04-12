S = input()
A = 0
B = 0

for s in S:
    if s == "A":
        A += 1
    else:
        B += 1
if A == 0 or B == 0:
    print("No")
else:
    print("Yes")