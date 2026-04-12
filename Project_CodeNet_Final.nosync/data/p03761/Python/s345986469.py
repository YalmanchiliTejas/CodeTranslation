import string
n = int(input())
S = [sorted(list(input())) for _ in range(n)]

ans = ""
ref = 'abcdefghijklmnopqrstuvwxyz'
lst = [51]*26

for i in range(26):
    for j in range(n):
        lst[i] = min(lst[i], S[j].count(ref[i]))
    if 0 < lst[i] < 51:
        ans = ans + ref[i]*lst[i]

print(ans)
