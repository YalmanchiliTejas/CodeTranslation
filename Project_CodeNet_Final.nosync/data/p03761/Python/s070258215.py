def main():
    n = int(input())
    counts = [[0] * 26 for _ in range(n)]
    for i in range(n):
        for c in input():
            counts[i][ord(c) - ord('a')] += 1
    counts_min = [min(counts[i][c_i] for i in range(n)) for c_i in range(26)]
    s = ''
    for c_i, c in enumerate(counts_min):
        if c > 0:
            s += chr(ord('a') + c_i) * c
    print(s)


if __name__ == '__main__':
    main()
