n = int(input())
s = [input() for _ in range(n)]
cnt = [float('inf')] * 26
for i in range(n):
    tmp = [0] * 26
    for j in s[i]:
        tmp[ord(j) - ord('a')] += 1
    for k in range(26):
        cnt[k] = min(cnt[k], tmp[k])
ans = ''
for i in range(26):
    for j in range(cnt[i]):
        ans += chr(ord('a') + i)
print(ans)