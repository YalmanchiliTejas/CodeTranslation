s = input()

ini = s[0]
for str in s:
    if str != ini:
        print("Yes")
        exit(0)
print("No")
