import sys
s = input()
bf = s[0]
for i in s[1:]:
    if i != bf:
        print("Yes")
        sys.exit()
print("No")
