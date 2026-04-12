S = input()
s = {}

for i in S:
    s[i] = 1

if len(s.keys()) > 1:
    print("Yes")
else:
    print("No")
    