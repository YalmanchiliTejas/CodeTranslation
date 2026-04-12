# Aizu Problem 0061: Rank Checker
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


points = {}    
while True:
    no, p = [int(_) for _ in input().split(',')]
    if no == p == 0:
        break
    if p not in points:
        points[p] = []
    points[p].append(no)
rank = sorted(list(points.keys()), reverse=True)

while True:
    try:
        team = int(input())
    except EOFError:
        break
    for i in range(len(rank)):
        if team in points[rank[i]]:
            print(i + 1)
            break