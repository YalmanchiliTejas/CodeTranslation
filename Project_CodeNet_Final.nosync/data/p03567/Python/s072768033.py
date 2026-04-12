s = input()
found = False
for i in range(len(s)-1):
    if s[i] == 'A' and s[i+1] == 'C':
        print('Yes')
        found = True
        break
if not found:
    print('No')
