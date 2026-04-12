N = input()
L = len(N)
K = int(input())


def main(d, k):
    if (L - d) < k:
        return 0
    if N[d] == "0":
        return main(d + 1, k)
    if k == 1:
        return ((L - d) - 1) * 9 + int(N[d])
    elif k == 2:
        return (
            ((((L - d) - 1) * ((L - d) - 2)) // 2) * 81
            + ((L - d) - 1) * 9 * (int(N[d]) - 1)
            + main(d + 1, k - 1)
        )
    elif k == 3:
        return (
            ((((L - d) - 1) * ((L - d) - 2) * ((L - d) - 3)) // 6) * (9 ** 3)
            + ((((L - d) - 1) * ((L - d) - 2)) // 2) * 81 * (int(N[d]) - 1)
            + main(d + 1, k - 1)
        )


print(main(0, K))

