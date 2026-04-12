def resolve():
    s = input()
    c = set()

    for cha in s:
        c.add(cha)

    if len(c) == 1:
        print('No')

    else:
        print('Yes')

resolve()