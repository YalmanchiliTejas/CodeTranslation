s = input()

a = False
for i in range(len(s)):
    if s[i] == "A":
        a = True
        break

b = False
for i in range(len(s)):
    if s[i] == "B":
        b = True
        break

if a and b:
    print("Yes")
else:
    print("No")