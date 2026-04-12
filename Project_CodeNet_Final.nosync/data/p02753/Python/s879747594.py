S = input()
a = 0
b = 0
for s in S:
    if s == "A":
        a += 1
    elif s == "B":
        b += 1
if a == 0 or b == 0:
    print("No")
else:
    print("Yes")
