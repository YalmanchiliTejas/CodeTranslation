n = int(input())
h = list(map(int, input().split()))
tmp = [1] * n

for i in range(0, n):
    for j in range(i, n):
        if h[i] > h[j]:
            tmp[j] = 0
print(tmp.count(1))
