if __name__ == '__main__':

    n = int(input())
    xs = [int(c) for c in input().split()]

    xs_sorted = sorted(xs)
    cand_s, cand_l = xs_sorted[n // 2 - 1], xs_sorted[n // 2]

    for x in xs:
        print(cand_l if x <= cand_s else cand_s)

