S = input()
A = 0
B = 0
for i in S:
    if i == "A":
        A+=1
    elif i == "B":
        B += 1

if A == 3 or B == 3:
    print("No")
else:
    print("Yes")