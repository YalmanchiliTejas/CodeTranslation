n, m = map(int, input().split())

a = []
b = []
for i in range(m):
    tmp1, tmp2 = map(int, input().split())
    a.append(tmp1)
    b.append(tmp2)

link = []

for i in range(n):
    num = i + 1
    link.append([])
    for a_i, b_i in zip(a, b):
        if a_i == num:
            link[i].append(b_i)
        if b_i == num:
            link[i].append(a_i)
pass_count = 0

hie_ind = [0 for i in range(n)]
pass_his = [1]
finish = False
while True:
    if len(pass_his) == n:
        pass_count += 1
        pass_his.pop()

    hierarchy = len(pass_his) - 1
    now_n = pass_his[-1]-1
    now_ind = hie_ind[hierarchy]

    while True:
        if now_ind > (len(link[now_n]) - 1):
            if now_n == 0:
                finish = True
                break
            pass_his.pop()
            hie_ind[hierarchy] = 0

            hierarchy = len(pass_his) - 1
            now_n = pass_his[-1]-1
            now_ind = hie_ind[hierarchy]
        else:
            break
    if finish:
        break

    cand_n = link[now_n][now_ind]

    if not(cand_n in pass_his):
        pass_his.append(cand_n)
    hie_ind[hierarchy] += 1

print(pass_count)

