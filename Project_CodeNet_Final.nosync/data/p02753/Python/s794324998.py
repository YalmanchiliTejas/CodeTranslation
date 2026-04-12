s = input()
prev = s[0]
for si in s:
    if prev != si:
        print("Yes")
        exit()

print("No")

