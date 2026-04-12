n = int(input())
s = [input() for _ in range(n)]
ans = [float('inf')] * 26
for i in range(n):
    cnt = [0] * 26
    for j in s[i]:
        cnt[ord(j) - ord('a')] += 1
    for j in range(26):
        ans[j] = min(ans[j], cnt[j])
test = ''
for i in range(26):
    for _ in range(ans[i]):
        test += chr(i + ord('a'))
print(test)
