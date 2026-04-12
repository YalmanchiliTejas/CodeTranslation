def abc():
    input()
    h = list(map(int, input().rstrip().split()))

    c = 0
    for i, x in enumerate(h):
        viewable = True
        for j in range(i+1):
            if h[j] > h[i]:
                viewable = False
        else:
            if viewable:
                c += 1
    print(c)


abc()
