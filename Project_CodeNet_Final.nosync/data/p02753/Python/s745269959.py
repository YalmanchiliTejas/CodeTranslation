S = input()

fa = 0
fb = 0
for i in range(3):
    if S[i] == "A":
        fa = 1
    if S[i] == "B":
        fb = 1

if fa == 1 and fb == 1:
    print("Yes")
else:
    print("No")