def asindex(c):
    return ord(c) - ord('a')


def asstr(i):
    return chr(i + ord('a'))


def main():
    n = int(input())
    S = [[0 for _ in range(n)] for _ in range(26)]

    for i in range(n):
        for c in input():
            S[asindex(c)][i] += 1

    ans = ''
    for i in range(26):
        freq = min(S[i])
        
        for _ in range(freq):
            ans += asstr(i)

    print(ans)


if __name__ == "__main__":
    main()