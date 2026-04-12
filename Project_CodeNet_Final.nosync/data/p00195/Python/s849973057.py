while True:
    try:
        n = [[0,"A"],[0,"B"],[0,"C"],[0,"D"],[0,"E"]]
        for i in range(5):
            n[i][0] = sum(list(map(int,input().split())))
        n.sort(reverse = True)
        print(n[0][1],n[0][0])
    except:
        break
