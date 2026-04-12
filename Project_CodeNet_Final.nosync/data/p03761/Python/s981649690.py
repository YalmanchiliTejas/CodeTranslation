def main():
    strings = "abcdefghijklmnopqrstuvwxyz"
    n = int(input())
    dict = {s: 0 for s in strings}
    first = input()
    for s in first:
        dict[s] += 1

    for _ in range(n-1):
        counts = {s: 0 for s in strings}
        S = input()
        for s in S:
            counts[s] += 1

        for s, count in counts.items():
            if count < dict[s]:
                dict[s] = count

    ans = ""
    for s in sorted(dict.keys()):
        count = dict[s]
        ans += s * count

    print(ans)


if __name__ == "__main__":
    main()
