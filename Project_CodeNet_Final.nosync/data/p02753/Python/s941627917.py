s = input()
a = 0
b = 0
for x in s:
    if x == 'A': a += 1
    if x == 'B': b += 1
if a == 0 or b == 0: print('No')
else: print('Yes')