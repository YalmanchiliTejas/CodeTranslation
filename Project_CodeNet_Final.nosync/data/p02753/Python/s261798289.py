s = input()

a = [0, 0]
for si in s:
    if si == 'A':
        a[0] = 1
    else:
        a[1] = 1

if a[0] == 1 and a[1] == 1:
    print("Yes")
else:
    print("No")