# Aizu Problem 00124: League Match Score Sheet
#
import sys, math, os, copy

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


first = True
while True:
    N = int(input())
    if N == 0:
        break
    if first:
        first = False
    else:
        print()
    scoresheet = []
    for n in range(N):
        s = input().split()
        team = s[0]
        won = int(s[1])
        draw = int(s[3])
        scoresheet.append([team, n, 3 * won + draw])
    scoresheet = sorted(scoresheet, key=lambda x: (-x[2], x[1]))
    for team, n, points in scoresheet:
        print("%s,%d" % (team, points))
    