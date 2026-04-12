n = int(input())
s = []
for i in range(n):
    s.append(input())

set_s = sorted(set(s[0]))
nn = int(len(set_s))
ans = [[] for i in range(nn)]
for i in range(nn):
    for j in s:
        ans[i].append(j.count(set_s[i]))

ans_2 = []
c = 0
for i in ans:
    i = min(i)
    for j in range(i):
        ans_2.append(set_s[c])
    c += 1

for j in ans_2:
    print(j,end="")
