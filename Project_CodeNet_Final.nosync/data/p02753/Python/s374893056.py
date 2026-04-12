from collections import Counter
s = input()

a = False
b = False
for i in s:
    if i == "A":
        a = True
    elif i == "B":
        b = True

if a and b:
    print("Yes")
else:
    print("No")
