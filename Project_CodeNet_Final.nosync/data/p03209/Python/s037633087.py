N, X = [int(i) for i in input().split()]
p = [1]
l = 1
for i in range(N):
    p.append(p[-1] * 2 + 1)
    l = 2 * l + 3
ban_l = 1
ban_r = l
pate = l//2+1
cnt = 0
for i in range(N+1):
    if X == pate:
        if pate == ban_l:
            cnt += 1
            break
        else:
            cnt += p[N-(i+1)] + 1
            break
    elif X == ban_l:
        break
    elif X < pate:
        ban_l = ban_l + 1
        ban_r = pate - 1
        pate = (pate+ban_l)//2
    elif X < ban_r:
        cnt += p[N-(i+1)] + 1
        ban_l = pate + 1
        pate = (pate+ban_r)//2
        ban_r = ban_r - 1
    else:
        cnt += p[N-i]
        break
print(cnt)