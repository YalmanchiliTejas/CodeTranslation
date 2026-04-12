s = str(input())
tmp = s[0]

for c in s:
    if tmp != c:
        print("Yes")
        exit()
else:
    print("No")
