n = input()
k = int(input())

def take_k_comb(a, b):
    if b == 0:
        return 1
    if b == 1 and a >= 1:
        return a * 9
    if b == 2 and a >= 2:
        return a*(a-1)//2 * 9 * 9
    if b == 3 and a >= 3:
        return a*(a-1)*(a-2)//6*9*9*9
    return 0

def constrained_nk(n, k):
    if k == 0:
        return 1
    if n == "":
        if k == 0:
            return 1
        else:
            return 0
    h = int(n[0])
    rest = n[1:]
    if h == 0:
        return constrained_nk(rest, k)
    s = take_k_comb(len(rest), k)
    s += (h-1) * take_k_comb(len(rest), k - 1)
    s += constrained_nk(rest, k-1)
    return s

print(constrained_nk(n, k))


