N = int(input())
Xlist = list(map(int,input().split()))
Xcopy = Xlist.copy()
Xcopy.sort()
Xsm = Xcopy[N//2-1]
Xla = Xcopy[N//2]
if Xsm == Xla:
    for _ in range(len(Xlist)):
        print(Xsm)
else:
    for i in range(len(Xlist)):
        Tar = Xlist[i]
        if Tar <= Xsm:
            print(Xla)
        else:
            print(Xsm)