s = input()
ln = len(s)

for i in range(0, ln-1):
    if s[i] != s[i+1]:
        print('Yes')
        exit()
print('No')