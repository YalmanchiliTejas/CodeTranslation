n = int(input())

cnt = [10000] * 26

for i in range(n):
    s = input()
    tmp = [0] * 26
    for c in s:
        tmp[ord(c) - ord('a')] += 1
    for j in range(26):
        cnt[j] = min(cnt[j], tmp[j])

a = ''
for i in range(26):
    if cnt[i]:
        a = a + chr(ord('a') + i) * cnt[i]
print(a)
