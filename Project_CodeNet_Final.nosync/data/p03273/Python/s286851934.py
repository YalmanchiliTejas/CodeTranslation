#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]
#a = [list(input()) for _ in range(n)]

h,w = map(int, input().split())
a = [input() for _ in range(h)]

y = [False] * h
x = [False] * w

for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            y[i] = True
            x[j] = True

for i in range(h):
    if y[i]:
        for j in range(w):
            if x[j]:
                print(a[i][j],end="")
        print("")



