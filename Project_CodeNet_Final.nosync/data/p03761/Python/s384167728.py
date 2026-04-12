import collections


def main():
    N = int(input())
    S = [input()for n in range(N)]
    counter = [100] * 26
    for s in S:
        S_count = collections.Counter(s)
        for i in range(26):
            counter[i] = min(counter[i], S_count[chr(i + 97)])

    ans = ''
    for i in range(26):
        ans = ans + (chr(i + 97) * counter[i])
    print(ans)


if __name__ == "__main__":
    main()