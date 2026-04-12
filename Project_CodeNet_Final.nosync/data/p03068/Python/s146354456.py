n = int(input())
s =input()
k = int(input())

ans = []
for i in s:
    if i == s[k-1]:
        ans.append(i)
    else:
        ans.append('*')

print(''.join(ans))