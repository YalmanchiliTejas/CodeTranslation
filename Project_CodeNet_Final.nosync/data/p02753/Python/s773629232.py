s = input()
fg = 0
for i in range(2):
    if s[i] != s[i+1]:
        fg = 1
if fg == 1:
    print("Yes")
else:
    print("No")