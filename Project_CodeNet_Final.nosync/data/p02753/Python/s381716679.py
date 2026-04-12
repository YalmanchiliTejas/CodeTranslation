a = input()
b = a[0] + a[1]
c = a[0] + a[2]
d = a[1] + a[2]
if b == "AB" or b == "BA":
    print("Yes")
elif c == "AB" or c == "BA":
    print("Yes")
elif d == "AB" or d == "BA":
    print("Yes")
else:
    print("No")