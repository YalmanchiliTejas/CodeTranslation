import re
s = input()
x = s[0]
m = re.match(x+x+x,s)
if m:
    print("No")
    exit()
print("Yes")
