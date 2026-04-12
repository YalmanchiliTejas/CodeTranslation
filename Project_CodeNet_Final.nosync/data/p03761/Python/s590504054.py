def asindex(c):
    return ord(c) - ord('a')


def asstr(i):
    return chr(i + ord('a'))


def main():
    n = int(input())
    S = [50 for _ in range(26)]

    for _ in range(n):
        tmp = [0 for _ in range(26)]
        for c in input():
            tmp[asindex(c)] += 1

        for i in range(26):
            S[i] = min(S[i], tmp[i])

    ans = ''
    for i in range(26):
        for _ in range(S[i]):
            ans += asstr(i)

    print(ans)


if __name__ == "__main__":
    main()
