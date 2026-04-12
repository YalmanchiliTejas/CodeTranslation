n = int(input())
s = [list(input()) for i in range(n)]

se = set(s[0])
for j in s:
    se &= set(j)

ls = list(se)
ls.sort()

ans = ""
for k in range(len(ls)):
    a_count = 10**6
    char = ls[k]

    for j in s:
        count = j.count(char)
        a_count = min(a_count, count)

    for m in range(a_count):
        ans += char

print(ans)
