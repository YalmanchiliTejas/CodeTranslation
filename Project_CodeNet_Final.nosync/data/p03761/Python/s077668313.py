n = int(input())
s = []
for i in range(n):
    s.append(list(input()))
ans = []
for i in range(len(s[0])):
    cnt = 0
    for j in range(n):
        if s[0][i] in s[j]:
            cnt += 1
    if cnt == n:
        ans.append(s[0][i])
        for j in range(1,n):
            s[j].remove(s[0][i])
ans.sort()
print(''.join(ans))