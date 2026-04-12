import sys

sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
        H, W = map(int, input().split())
        maze = [input() for _ in range(H)]
        cnt=0
        for i in maze:
            for j in i:
                if j=='#':
                    cnt+=1
        print('Possible' if cnt==(H-1)+(W-1)+1 else 'Impossible')

resolve()