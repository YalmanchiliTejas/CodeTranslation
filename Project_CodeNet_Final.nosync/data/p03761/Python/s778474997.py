n = int(input())
s = []
for _ in range(n):
    s.append(input())
common = [100]*26
for ss in s:
    tmp = [0]*26
    for c in ss:
        tmp[ord(c)-ord('a')] += 1
    for i in range(26):
        common[i] = min(common[i], tmp[i])

ans = ''
for i in range(26):
    ans += chr(i+ord('a'))*common[i]
print(ans)