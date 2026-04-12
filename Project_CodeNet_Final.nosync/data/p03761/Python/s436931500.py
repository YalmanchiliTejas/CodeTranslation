n = int(input())
ans = list(input())

for i in range(n - 1):
    s = list(input())
    tmp = []
    for i in range(len(s)):
        if s[i] in ans:
            tmp.append(s[i])
            ans.remove(s[i])
    ans = tmp
    
ans.sort()
print(''.join(ans))