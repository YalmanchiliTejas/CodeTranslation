N = input()
L = len(N)
K = int(input())


def main(d, k):
    if d == L:
        if k == 0:
            return 1
        else:
            return 0
    if N[d] == "0":
        return main(d + 1, k)
    if (L - d) < k:
        return 0
    if k == 0:
        return 1
    return main1(d+1, k)+main1(d+1, k-1)*(int(N[d])-1)+main(d+1, k-1)


lmain1 = [[-1 for j in range(K+1)] for i in range(L+1)]


def main1(d, k):
    if d == L:
        if k == 0:
            return 1
        else:
            return 0
    if k == 0:
        return 1
    if lmain1[d][k] != -1:
        return lmain1[d][k]
    ret = main1(d+1, k-1)*9+main1(d+1, k)
    lmain1[d][k] = ret
    return ret


print(main(0, K))
