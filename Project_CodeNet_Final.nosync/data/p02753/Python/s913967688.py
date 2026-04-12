str  = input()
a = False
b = False
for ch in str:
    if ch == 'A':
        a = True
    else:
        b = True
if a and b:
    print("Yes")
else:
    print("No")
