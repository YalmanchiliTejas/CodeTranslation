N = int(input())
l = list(map(int,input().split()))

INF = 10 ** 17

start = []
start.append((0, l[0]))
start.append((0,max(l[0],l[1])))

for i in range(2, N):
    if i % 2 == 0:
        left = [start[-1][1], start[-2][0] + l[i]]
        right = [start[-2][1] + l[i]]
    else:
        left = [start[-1][0], start[-2][0] + l[i]]
        right = [start[-1][1], start[-2][1] + l[i]]
    start.append((max(left),max(right)))

if N % 2:
    print(start[-1][0])
else:
    print(start[-1][1])
