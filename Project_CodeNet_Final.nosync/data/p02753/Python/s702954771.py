S = input()
a = []
for i in range(0, 3):
    a.append(S[i])

if a[0] == a[1] == a[2]:
    print("No")
else:
    print("Yes")
