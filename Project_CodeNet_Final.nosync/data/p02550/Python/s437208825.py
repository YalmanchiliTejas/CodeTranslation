def resolve():
    N, X, M = map(int, input().split())
    x = X
    mod = [x]
    while x**2 % M not in mod:
        mod.append(x**2%M)
        x = x**2%M

    ans = 0
    if N <= len(mod):
        for i in range(N):
            ans += mod[i]
    else:
        if mod[-1] == 1:
            ans = sum(mod) + N-len(mod)
        elif mod[-1] == 0:
            ans = sum(mod)
        else:
            first = mod.index(mod[-1]**2%M)
            head = mod[:first]
            loop = mod[first:]

            mo = (N-first)%len(loop)
            div = (N-first)//len(loop)
            ans += sum(head)+ div*sum(loop)
            for i in range(mo):
                ans += loop[i]
    print(ans)
resolve()