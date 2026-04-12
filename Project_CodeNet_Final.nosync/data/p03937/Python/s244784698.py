import numpy as np
h, w = map(int,input().split())
way = []
for i in range(h):
    s = input()
    for j in range(w):
        if s[j] == "#":
            way.append([i,j])

for i in range(len(way)-1):
    if (way[i+1][0]-way[i][0])+(way[i+1][1]-way[i][1]) == 1 and (way[i+1][0]-way[i][0])*(way[i+1][1]-way[i][1]) == 0:
        continue
    else:
        print("Impossible")
        exit()

print("Possible")
