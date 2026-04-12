import sys

while True:
    slist = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0}
    for c in 'ABCDE':
        s1, s2 = map(int, input().split())
        if s1 == 0 and s2 == 0:
            sys.exit()
        slist[c] = s1+s2
    print(*sorted(slist.items(), key=lambda x: x[1])[-1])

