n = int(input())
s = input()
k = int(input())

ans = []

for i, l in enumerate(s):
    if s[i] == s[k-1]:
        ans.append(s[i])
    else:
        ans.append('*')

print(''.join(ans))