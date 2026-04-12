from collections import deque
N = int(input())
H = list(map(int, input().split()))
V = deque()
for i in range(len(H)):
    counter = 0
    for j in range(i):
        if H[i] >= H[j]:
            counter += 1
    if counter == i :
        V.append(H[i])
print(len(V))


