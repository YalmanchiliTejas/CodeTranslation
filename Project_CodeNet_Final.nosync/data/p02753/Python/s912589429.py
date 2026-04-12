T = input()

a = 0
b = 0 
for s in T:
    if s == 'A':
        a += 1
    elif s == 'B':
        b += 1

if a == 3 or b == 3:
    print("No")
else:
    print('Yes')