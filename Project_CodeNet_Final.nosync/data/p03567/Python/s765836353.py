s = input()
flag = False
for i in range(len(s) - 1):
    if s[i:i + 2] == "AC":
        flag = True
        break
if flag == True:
    print("Yes")
else:
    print("No")