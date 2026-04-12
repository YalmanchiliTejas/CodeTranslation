s = list(input())
s.append(s[0])
ans = False
for i in range(len(s)-1):
    if s[i] != s[i+1]:
        ans = True
if ans:
    print('Yes')
else:
    print('No')
