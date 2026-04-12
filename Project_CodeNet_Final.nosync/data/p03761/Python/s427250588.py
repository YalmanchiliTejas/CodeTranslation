n = int(input())
S = [input() for i in range(n)]
check = set()

for i in S:
    for j in i:
        check.add(j)

check = sorted(check)
num_list = []
for i in check:
    num = float('inf')
    for j in S:
        num = min(num, j.count(i))
    num_list.append(num)

ans = [check[i] * num_list[i] for i in range(len(check))]

print(''.join(ans))