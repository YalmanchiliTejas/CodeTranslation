import sys
input = sys.stdin.readline

H,W = list(map(int,input().split()))
cell = []
for i in range(H):
    s=list(input().rstrip())
    cell.append(s)
h = set(range(H))
w = set(range(W))
sh = []
sw = []
for ih in range(H):
    for iw in range(W):
        if cell[ih][iw] == '#':
            sh.append(ih)
            sw.append(iw)
sh = set(sh)
sw = set(sw)
for iih in sh:
    for iiw in sw:
        print(cell[iih][iiw],end='')
    print('')