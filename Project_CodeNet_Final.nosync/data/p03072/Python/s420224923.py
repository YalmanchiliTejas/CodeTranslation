def sub():
    N, Hs = [input() for _ in range(2)]
    Hs = [int(e) for e in Hs.split(" ")]
    count = 1
    maxH = Hs[0]
    for i in range(1, int(N)):
        h = Hs[i]
        if h >= maxH:
            count = count + 1
            maxH = h


    print("{}".format(count))

sub()

