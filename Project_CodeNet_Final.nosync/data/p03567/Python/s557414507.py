s = list(input())

for i in range(len(s)):
    if i+1 < len(s):
        if s[i]+s[i+1] == 'AC':
            print('Yes')
            exit()
print('No')