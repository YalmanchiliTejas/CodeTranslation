s = input()

for i in range(len(s)):
    if s[i-1] != s[i]:
        print('Yes')
        exit()
print('No')