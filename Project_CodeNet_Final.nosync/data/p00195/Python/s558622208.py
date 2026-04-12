import sys,os
while 1:
    a = []
    for i in range(5):
        a.append(list(map(int, input().split())))
        if a == [[0,0]]:
            sys.exit(0)

    ans = 0
    abcde = "ABCDE"
    an = ""
    for j,i in enumerate(a):
        if ans < i[0]+i[1]:
            ans = i[0]+i[1]
            an = abcde[j]

    print(an,ans)
