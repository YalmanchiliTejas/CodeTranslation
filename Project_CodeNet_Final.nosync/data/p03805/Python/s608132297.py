import itertools


def main():
    # 入力
    n, m = map(int, input().split())

    ablist = []
    for i in range(m):
        a, b = map(int, input().split())
        ablist.append((a, b))

    list = [x for x in range(2, n+1)]
    permutations_lis = itertools.permutations(list)

    count = 0
    for perlist in permutations_lis:
        # 1は特殊
        i_current = 1
        i_already = {1}

        root = []

        countable = True
        for p in perlist:
            i_target = p

            found = False
            for ab in ablist:
                if ab in root:
                    continue
                if ab[0] == i_current and ab[1] == i_target:
                    root.append(ab)
                    i_current = ab[1]
                    found = True
                    break
                elif ab[1] == i_current and ab[0] == i_target:
                    root.append(ab)
                    i_current = ab[0]
                    found = True
                    break

            if not found:
                countable = False
                break

        if countable:
            count += 1

    print(count)


main()
