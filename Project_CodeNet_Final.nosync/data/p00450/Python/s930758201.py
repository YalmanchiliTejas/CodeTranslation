while 1:
    n = input()
    if n == 0: break
    l = [0,0]
    l += [input()]
    l += [1]
    for i in range(n-1):
        x = input()
        if i % 2 == 1:
            if l[-2] == x: l[-1] += 1
            else: l += [x]; l += [1]
        else:
            if l[-2] == x: l[-1] += 1
            else:
                if len(l) > 2:
                    l[-3] += l[-1] + 1
                    l = l[:-2]
                else:
                    l[-2] = x
                    l[-1] += 1
    ans = 0
    for i in range(len(l)/2):
        if l[i*2] == 0: ans += l[i*2 + 1]
    print ans