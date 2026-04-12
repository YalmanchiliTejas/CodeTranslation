N, X = map(int, input().split())

burgersize, pnum = [1], [1]
for i in range(N):
    burgersize.append(burgersize[-1] * 2 + 3)
    pnum.append(pnum[-1] * 2 + 1)

def count_p(level, X):
    if X == 0:
        return 0
    if X == burgersize[level]:
        return pnum[level]
    if level == 0:
        return 1
    Xmid = (burgersize[level] - 1) // 2 + 1
    if X < Xmid:
        return count_p(level - 1, X - 1)
    else:
        return pnum[level - 1] + 1 + count_p(level - 1, X - Xmid)

print(count_p(N, X))