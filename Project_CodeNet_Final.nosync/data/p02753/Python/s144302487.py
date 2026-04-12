S=input()
a=1
if S[0] == 'A':
    if S[1] == 'A':
        if S[2] == 'A':
            a = 0
if S[0] == 'B':
    if S[1] == 'B':
        if S[2] == 'B':
            a = 0

if a == 0:
    print('No')
else:
    print('Yes')