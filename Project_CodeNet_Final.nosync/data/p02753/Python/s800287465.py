a = list(input())
A_flag = False
B_flag = False

for n in range(3) :
    if a[n] == "A":
        A_flag = True
    elif a[n] == "B":
        B_flag = True
if A_flag and B_flag:
    print("Yes")
else:
    print("No")