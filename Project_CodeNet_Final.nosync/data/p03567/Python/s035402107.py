s = list(str(input()))
a = 0

for i in range(len(s)-1):
    if s[i] == 'A' and s[i+1] == 'C':
        a += 1
    else:
        a += 0
if a>= 1:
    print('Yes')
else:
    print('No')