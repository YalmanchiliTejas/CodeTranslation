s = input()
p = s[0]
for i in range(len(s)):
    if s[i] != p:
        print('Yes')
        exit()
print('No')