while True:
    n = int(raw_input())
    if n == 0:
        break
    li = []

    for i in xrange(n):
        p = int(raw_input())
        if i == 0:
            li.append([p, 1])
            continue
        # odd
        if i % 2 == 0:
            if li[-1][0] == p:
                li[-1][1] += 1
            else:
                li.append([p, 1])
        else:
            if li[-1][0] == p:
                li[-1][1] += 1
            else:
                li[-1][0] = p
                li[-1][1] += 1
                if len(li) >= 2 and li[-2][0] == li[-1][0]:
                    li[-2][1] += li[-1][1]
                    del li[-1]

    print sum(t[1] for t in li if t[0] == 0)