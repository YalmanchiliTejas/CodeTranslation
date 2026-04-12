while True:
    n = int(input())
    if n==0: break
    edge = 0
    sq = 0
    past = []

    for i in range(n):
        nxt = int(input())
        if i==0:
            edge = nxt

        if i%2 == 0:
            if nxt == edge:
                sq += 1
            else:
                edge = nxt
                past.append(sq)
                sq = 1
        else:
            if nxt == edge:
                sq += 1
            else:
                edge = nxt
                sq += 1
                if len(past) != 0:
                    sq += past.pop()
    past.append(sq)

    answer = 0
    for i in range(len(past)):
        if edge == 0:
            answer += past[-i-1]
        edge = 1 - edge

    print(answer)