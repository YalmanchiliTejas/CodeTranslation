n = int(input())
s = [input() for i in range(n)]
s.sort(key=lambda x: len(x))

pivot = s[0]
min_letters = ""
for i in range(0, len(pivot)):
    ele = pivot[i]
    for j in range(1, n):
        if s[j].count(pivot[i]):
            pos = s[j].find(pivot[i])
            tmp_list = list(s[j])
            tmp_list[pos] = ""
            s[j] = "".join(tmp_list)
        else:
            ele = ""
    min_letters += ele

ans_list = list(min_letters)
ans_list.sort()
print("".join(ans_list))
