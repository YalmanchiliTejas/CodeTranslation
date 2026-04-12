s = input()
y = 0
for i in range(len(s)-1):
    if s[i:i+2] == "AC":
        y = 1
if y == 1:
    print("Yes")
else:
    print("No")