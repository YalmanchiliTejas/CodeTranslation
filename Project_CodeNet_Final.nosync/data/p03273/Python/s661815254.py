
import math
H,W = list(map(int,input().split(" ")))
mas = []
for _ in range(H):
    temp = input()
    if temp == "."*W :
        temp = "-" * W
    mas.append(list(temp))
for w in range(W):
    flag = True
    for h in range(H):
        if mas[h][w]  == "#":
            flag = False
            break
    if flag:
        for h in range(H):
            mas[h][w] = "-"

for h in range(H):
    flag = False
    for w in range(W):
         if mas[h][w] != "-":
            print(mas[h][w],end="")
            flag = True
    if flag:
        print()
