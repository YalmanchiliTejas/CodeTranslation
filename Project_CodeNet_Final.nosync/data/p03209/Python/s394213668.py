def do(lv, dan):
    res = 0
    #print("do({0}, {1})".format(lv, dan))
    if lv == 0:
        if dan == 0:
            return 0
        elif dan == 1:
            return 1
        else:
            print("!!!!!!!!!!!!!!!!!!!!!!!!!!")
    if dan == 0:
        return 0

    dan -= 1

    if dan == 0:
        return 0

    if burgersize[lv-1] <= dan:
        res += pnum[lv-1]
        dan -= burgersize[lv-1]
    else:
        res = do(lv-1, dan)
        dan = 0

    if dan >= 1:
        res += 1
        dan -= 1
    else:
        return res

    if burgersize[lv-1] <= dan:
        res += pnum[lv-1]
        dan -= burgersize[lv-1]
    else:
        res += do(lv-1, dan)
        dan = 0


    return res

burgersize = [1] * 51
pnum = [1] * 51
for i in range(1, 51):
    burgersize[i] = burgersize[i-1] * 2 + 3
    pnum[i] = pnum[i-1] * 2 + 1
#print(burgersize[:10])
#print(pnum[:10])
a,b = map(int, input().split())
print(do(a, b))
