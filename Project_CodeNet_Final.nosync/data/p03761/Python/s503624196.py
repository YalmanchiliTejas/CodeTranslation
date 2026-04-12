N = int(input())
if N == 1:
    u = ''.join(sorted(list(input())))
    print(u)
else:
    os = input()
    news = ''
    l = [-1] * len(os)
    for _ in range(N-1):
        s = input()
        for i,c in enumerate(os):
            for j,d in enumerate(s):
                if c == d:
                    if j in l:pass
                    else:
                        l[i] = j
                        news = news + c
                        break
        os = news
        news = ''
        l = [-1] * len(os)
    u = ''.join(sorted(list(os)))
    print(u)