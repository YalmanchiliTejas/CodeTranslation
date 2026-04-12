s = input()

a = 0
b = 0
for x in s:
    if x == 'A':
        a += 1
    elif x == 'B':
        b += 1
if a == 3 or b == 3:
    print('No')
else:
    print('Yes')