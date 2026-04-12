from queue import Queue
h, w = map(int, input().split())

fie = [list(input())for i in range(h)]
dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]


cant = 0
que = Queue()
que.put([0,0])

while not que.empty():
        px, py = que.get()
        fie[px][py] = "."
        under = right = 0
        for i in range(4):
                if 0<=px+dx[i]<h and 0<=py+dy[i]<w and fie[px+dx[i]][py+dy[i]]=="#":
                        if i==2 or i==3: cant = 1
                        else:
                                if i==0: under = 1
                                elif i==1: right = 1
                                que.put([px+dx[i],py+dy[i]])
        if under and right: cant = 1

if cant: print("Impossible")
else: print("Possible")