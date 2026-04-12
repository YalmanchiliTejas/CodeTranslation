s = input()
flg = 0
n = len(s)
for i in range(n-1):
    if s[i] == "A" and s[i+1] == "C":
        flg = 1
        break
    else:
        flg = 0
if flg == 1:
    print("Yes")
else:
    print("No")