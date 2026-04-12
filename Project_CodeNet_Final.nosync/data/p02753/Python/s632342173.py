s = input()
n = s[0]
tf = 1
for i in s:
    if n != i:
        print("Yes")
        tf = 0
        break
if tf == 1:
    print("No")