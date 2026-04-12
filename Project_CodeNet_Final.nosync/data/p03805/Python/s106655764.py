import numpy as np
import itertools
import queue

def accept_input():
    N,M = map(int,input().split())
    G = {}
    for _ in range(M):
        a,b = map(int,input().split())
        if a not in G:
            G[a] = [b]
        else:
            G[a].append(b)
        if b not in G:
            G[b] = [a]
        else:
            G[b].append(a)
    return N,M,G


def widthsearch(q):
    global curvisited
    movelist = [(0,1),(0,-1),(1,0),(-1,0)] 
    lastplace = ((0,0),0)
    cur = 0
    while curvisited < H*W:
        q1 = queue.Queue()
        cur += 1
        while not q.empty():
            pack = q.get()
            y = pack[0][0]
            x = pack[0][1]
            num = pack[1]
            for move in movelist:
                if y+move[0] == -1 or y + move[0] == H or x+move[1] == -1 or x + move[1] == W:
                    continue
                elif visitedlist[y+move[0]][x+move[1]] == 1:
                    continue
                elif S[y+move[0]][x+move[1]] == "#":
                    continue
                else:
                    visitedlist[y+move[0]][x+move[1]] = 1
                    curvisited += 1
                    q1.put(((y+move[0],x+move[1]),num+1))
            if curvisited == H*W:
                break
        q = q1
    return cur

N,M,G = accept_input()
l = []
for i in range(2,N+1):
    l.append(i)
al = 0
for comb in itertools.permutations(l, N-1):
    if comb[0] not in G[1]:
        continue
    for i in range(0,N-2):
        if comb[i+1] not in G[comb[i]]:
            break
    else:
        al += 1
print(al)
