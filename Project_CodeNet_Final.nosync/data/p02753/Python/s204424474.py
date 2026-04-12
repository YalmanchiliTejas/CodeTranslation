strin= input()

a = 0
b = 0

for kk in range(3):
    if strin[kk] == "A":
        a = 1
    if strin[kk] == "B":
        b = 1

if a == 1 and b == 1:
    print("Yes")
else:
    print("No")