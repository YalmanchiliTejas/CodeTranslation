import collections

def main():
    n = int(input())
    s = collections.Counter(input())
    cnt = {x:s[x] for x in s}
    for i in range(n-1):
        if len(cnt) == 0:
            break
        s = collections.Counter(input())
        for x in s:
            if x in cnt:
                cnt[x] = min(cnt[x], s[x])
        for x in list(cnt):
            if x not in s:
                cnt.pop(x)
    ans = ""
    for x in sorted(cnt):
        ans += x*cnt[x]
    print(ans)


if __name__ == '__main__':
    main()
