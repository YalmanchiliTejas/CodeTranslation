a = input()
b = a[0]
c = False
for i in range(len(a)):
    if a[i] != b:
        c = True
if c:
    print("Yes")
else:
    print("No")