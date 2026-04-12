n = int(input())
tmp = input()
s = list(tmp)
k = int(input())
for i in range(len(s)):
    if s[k-1] != s[i]:
        print('*',end='')
    else:
        print(s[k-1],end='')
print()