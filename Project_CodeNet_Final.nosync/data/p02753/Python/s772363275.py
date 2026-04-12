s = input()
prev = s[0]
for i in s[1:]:
    if prev!=i:
        print("Yes")
        break
    prev = i
else:
    print("No")