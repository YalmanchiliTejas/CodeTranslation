n = int(input())
strings = [list(input()) for _ in range(n)]

s_1 = list(strings.pop(0))
for s in strings:
    tmp = []
    for s_tmp in s_1:
        if s_tmp in s:
            tmp.append(s_tmp)
            s.remove(s_tmp)
    else:
        s_1 = tmp
s_1.sort()
print(''.join(s_1))