(n, x) = list(map(int, input().split()))

num = 1
pate = 1
for i in range(n):
    num = num * 2 + 3
    pate = pate * 2 + 1

def culc(l, idx, num, pate):
    npate = (pate - 1) // 2
    nnum = (num - 3) // 2
    mid = (num + 1) // 2
    if l == 1:
        if idx == 0:
            return 0
        elif idx == 1:
            return 0
        elif idx == 2:
            return 1
        elif idx == 3:
            return 2
        elif idx == 4:
            return 3
        else:
            return 3
    elif mid == idx:
        return npate + 1
    elif mid < idx:
        return npate + 1 + culc(l - 1, idx - mid, nnum, npate)
    else:
        return culc(l - 1, idx - 1, nnum, npate)
print(culc(n, x, num, pate))
