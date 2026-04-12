from collections import Counter, defaultdict
def main():
    n = int(input())
    S = list(input())
    c = Counter(S)
    d = dict(c)
    for _ in range(n - 1):
        S = list(input())
        c = Counter(S)
        for key in d.keys():
            d[key] = min(d[key], c[key])
    ans = []
    for key, value in d.items():
        ans.append(key * value)
    print(''.join(sorted(ans)))

if __name__ == '__main__':
    main()
