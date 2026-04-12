import sys;input()
for r in zip(*[c for c in zip(*[r for r in sys.stdin if'#'in r])if'#'in c]):print(*r,sep='')