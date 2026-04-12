n = int(input())
s = []
ans = []
for i in range(n):
    si = input()
    s.append(si)
s_set = set(list(s[0]))
for si in s_set:
    mm = 10000
    for i in range(n):
        mm = min(mm, s[i].count(si))
    for j in range(mm):
        ans.append(si)
ans = sorted(ans)
value = ""
for s in ans:
    value += s
print(value)