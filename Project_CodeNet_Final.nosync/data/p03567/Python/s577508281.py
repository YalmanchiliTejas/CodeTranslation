s = input()
count = 0
for i in range(len(s)-1):
    if s[i:i+2] == "AC":
        count = 1
        break
if count == 1:
    print("Yes")
else:
    print("No")