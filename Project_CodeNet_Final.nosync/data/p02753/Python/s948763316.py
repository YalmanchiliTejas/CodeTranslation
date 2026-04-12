S = input()
A,B = 0,0
for s in S:
    if s == 'A':
        A += 1
    else:
        B += 1

if A != 0 and B != 0:
    print('Yes')
else:
    print('No')
