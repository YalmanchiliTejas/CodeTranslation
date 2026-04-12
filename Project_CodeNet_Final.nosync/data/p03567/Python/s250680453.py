s = list(input())

f1 = False
f2 = False

for i in range(len(s)):
        if s[i] == 'A':
                f1 = True
        if f1 and s[i] == 'C':
                f2 = True
                f1 = False
                break
        if s[i] != 'A':
                f1 = False

if f2:
        print('Yes')
else:
        print('No')