while True:
    N,A,B,C,X = map(int,input().split())
    if N == 0: break
    ar = list(map(int,input().split()))
    ar.reverse()
    r = X
    for i in range(10001):
        if r == ar[-1]:
            ar.pop()
            if len(ar) == 0:
                print(i)
                break
        r = (A*r + B) % C
    else:
        print(-1)