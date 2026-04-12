N, M = map(int, input().split())
a = []
b = []
ans = 0
for i in range(M):
    x, y = map(int, input().split())
    a.append(x)
    b.append(y)

current_num = 1
fin_li = [1]
s_li = [[current_num,fin_li]]
while len(s_li) > 0:
    if len(s_li[0][1]) == N:
        ans += 1
    else:
        next_li = [b[i] for i, x in enumerate(a) if x == s_li[0][0]]
        next_li += [a[i] for i, x in enumerate(b) if x == s_li[0][0]]
        next_li = [[x, s_li[0][1]+[x]] for x in next_li if not x in s_li[0][1]]
        s_li += next_li
    s_li.pop(0)

print(ans)