from sys import stdin,setrecursionlimit
from itertools import groupby
setrecursionlimit(10**7)
h,w = map(int,stdin.readline().rstrip().split())
li = [["" for i in range(w)]for j in range(h)]
for i in range(h):
    s = stdin.readline().rstrip()
    for j in range(w):
        li[i][j] = s[j]
now = 0
last = 0
for i in range(h):
    flag = True
    for j in range(w):
        lin = []
        for key, value in groupby(li[i]):
            lin.append(key)
        if lin.count("#") >= 2:
            print("Impossible")
            exit()
        if li[i][j] == "#" and flag:
            flag = False
            now = j
        if i >= 1 and flag == False and now != last:
            print("Impossible")
            exit()
        if (flag == False and li[i][j] == "."):
            last = j-1
            break
        if  (not flag and j == w-1):
            last = j
            break
if last == w-1:
    print("Possible")
else:
    print("Impossible")