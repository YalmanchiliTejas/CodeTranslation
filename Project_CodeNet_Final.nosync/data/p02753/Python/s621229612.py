s = input()
flag = False
if (s[0] == 'A' and s[1] == 'B') or (s[0] == 'B' and s[1] == 'A'):
    flag = True

if (s[1] == 'A' and s[2] == 'B') or (s[1] == 'B' and s[2] == 'A'):
    flag = True

if flag:
    print("Yes")

else:
    print("No")