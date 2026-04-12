n = int(input())
h = list(map(int, input().split()))

ret = 0
for i in range(n):
    for j in range(i):
        if h[i] < h[j]:
            break
    else:
        ret += 1
print(ret)
