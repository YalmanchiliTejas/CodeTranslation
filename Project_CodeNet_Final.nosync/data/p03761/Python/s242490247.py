n = int(input())
z = [0 for _ in range(26)]
mn = [51 for _ in range(26)]
for _ in range(n):
    s = input()
    st = set(s)
    cnt = [0 for _ in range(26)]
    for i in range(len(s)):
        pos = ord(s[i]) - 97
        cnt[pos] += 1
    for ch in st:
        p = ord(ch) - 97
        z[p] += 1
    
    for k in range(len(mn)):
        if cnt[k] != 0 and cnt[k] < mn[k]:
            mn[k] = cnt[k]
            
ans = ""
for i in range(26):
    if z[i] == n:
        if mn[i] != 51:
            ans += chr(i+97)*mn[i]
            
print(ans)