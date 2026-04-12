N, X, M = map(int, input().split())

result = 0
loop_list = []
checked = set()
a = X
for i in range(N):
    result += a
    loop_list.append(a)
    checked.add(a)

    a = (a**2) % M
    if a == 0:
        break
    if a in checked:
        idx = loop_list.index(a)
        loop_list = loop_list[idx:]
        lp = (N - 1 - i) // len(loop_list)
        rem = (N - 1 - i) % len(loop_list)
        result += lp * sum(loop_list)
        result += sum(loop_list[:rem])
        break

print(result)

