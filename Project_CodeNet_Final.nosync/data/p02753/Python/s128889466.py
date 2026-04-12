s = list(input())
pre = s[0]
flag = True
for i in range(1, 3):
    if pre == s[i]:
        pass
    else:
        flag = False
    pre = s[i]
if flag:
    print("No")
else:
    print("Yes")
