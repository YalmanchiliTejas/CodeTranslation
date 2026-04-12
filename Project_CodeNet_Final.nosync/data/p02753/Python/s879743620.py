a = input()
count_A = 0
count_B = 0
for i in range(0,3):
    if a[i] == "A":
        count_A += 1
    if a[i] == "B":
        count_B += 1

if count_A == 3 or count_B == 3:
    print("No")
else:
    print("Yes")