n = int(input())
s = [input() for _ in range(n)]
al = []
lst = []
for i in s:
    for j in i:
        if not j in al:
            al.append(j)
al = sorted(al)

for i in al:
    num = float('inf')
    for j in s:
        num = min(num, j.count(i))
    lst.append(num)

result = [al[i] * lst[i] for i in range(len(al))]

print(''.join(result))