from collections import defaultdict, Counter


def main():
    N = int(input())
    counter = defaultdict(list)
    for _ in range(N):
        S = input()
        cnt = Counter(S)
        for c, v in cnt.items():
            counter[c].append(v)
    chars = list(counter.keys())
    chars.sort()
    ans = ''
    for c in chars:
        n = 0 if len(counter[c]) < N else min(counter[c])
        ans += c * n
    print(ans)



if __name__ == '__main__':
    main()