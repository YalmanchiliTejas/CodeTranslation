def main():
    from itertools import combinations

    N = raw_input()
    K = int(raw_input())
    digit = len(N)
    N = int(N)


    ans = 0

    # １桁目を考慮しない
    ans += len(list(combinations(range(digit - 1), K))) * (9 ** K)

    if K == 3:
        # 同じ長さの数を考える
        for top in range(1, 10):
            if int(str(N)[0]) < top:
                continue

            if int(str(N)[0]) > top:
                ans += len(list(combinations(range(digit - 1), K - 1))) * (9 ** (K - 1))
                continue

            for perm_digit in combinations(range(1, digit), K - 1):
                perm_digit = list(perm_digit)
                for pn1 in range(1, 10):
                    for pn2 in range(1, 10):
                        s = ['0'] * digit
                        s[0] = str(top)
                        s[perm_digit[0]] = str(pn1)
                        s[perm_digit[1]] = str(pn2)

                        if int(''.join(s)) <= N:
                            ans += 1

    elif K == 2:
        # 同じ長さの数を考える
        for top in range(1, 10):
            for perm_digit in combinations(range(1, digit), K - 1):
                perm_digit = list(perm_digit)

                for pn1 in range(1, 10):
                    s = ['0'] * digit
                    s[0] = str(top)
                    s[perm_digit[0]] = str(pn1)
                    if int(''.join(s)) <= N:
                        ans += 1

    elif K == 1:
        ans += int(str(N)[0])

    print(ans)


if __name__ == '__main__':
    main()