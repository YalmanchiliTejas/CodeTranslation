N, X = map(int, input().split())

burgersize, pnum = [1], [1]
for i in range(N):
    burgersize.append(burgersize[-1] * 2 + 3)
    pnum.append(pnum[-1] * 2 + 1)

def count_p(level, X):
    if level == 0:
        return 1
    elif X == burgersize[level]:
        return pnum[level]
    elif X == 1:
        return 0
    elif X < (burgersize[level] - 1) // 2 + 1:
        return count_p(level - 1, X - 1)
    elif X == (burgersize[level] - 1) // 2 + 1:
        return pnum[level - 1] + 1
    elif X > (burgersize[level] - 1) // 2 + 1:
        return pnum[level - 1] + 1 + count_p(level - 1, X - (burgersize[level] - 1) // 2 - 1)
    return None

ans = count_p(N, X)
print(ans)