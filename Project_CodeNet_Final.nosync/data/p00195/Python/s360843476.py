
while True:
    T = []
    am, pm = [int(x) for x in input().split()]
    if am == 0 and pm ==0:
        break
    T.append(am+pm)
    for i in range(4):
        am, pm = [int(x) for x in input().split()]
        T.append(am+pm)
    num = sorted(list(enumerate(T)), key=lambda x: -x[1])[0][0]
    print("ABCDEF"[num], T[num])




