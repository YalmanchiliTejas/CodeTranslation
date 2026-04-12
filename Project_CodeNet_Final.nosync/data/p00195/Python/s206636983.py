while True:
    a, b = map(int, raw_input().split())
    if a == b == 0: break
    ex = [0, a+b]
    for i in range(1, 5):
        a, b = map(int, raw_input().split())
        if ex[1] < a+b:
            ex = [i, a+b]
    else:
        if ex[0] == 0:
            print 'A', ex[1]
        elif ex[0] == 1:
            print 'B', ex[1]
        elif ex[0] == 2:
            print 'C', ex[1]
        elif ex[0] == 3:
            print 'D', ex[1]
        else:
            print 'E', ex[1] 