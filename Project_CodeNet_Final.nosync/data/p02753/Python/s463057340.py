a = input()
b = 0
c = 0
i = 0
while i < len(a) :
    if a[i] == "A" :
        b = b + 1
    if a[i] == "B" :
        c = c + 1
    i = i + 1
if (b > 0) and (c > 0) :
    print("Yes")
else:
    print("No")