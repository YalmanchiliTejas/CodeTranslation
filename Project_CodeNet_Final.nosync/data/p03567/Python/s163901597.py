s = list(input())

for i in range(len(s) - 1):
    if 'A' == s[i]:
        if 'C' == s[i + 1]:
            print('Yes')
            exit(0)

print('No')