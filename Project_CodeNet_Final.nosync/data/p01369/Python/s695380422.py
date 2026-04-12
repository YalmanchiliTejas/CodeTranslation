r = ['y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'n', 'm']

s = input()
while s != '#':
    cnt = 0
    for i in range(1, len(s)):
        prev = s[i - 1] in r
        cur = s[i] in r

        if prev != cur:
            cnt += 1

    print(cnt)

    s = input()


