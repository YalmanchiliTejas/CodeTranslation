n = int(input())
h = [int(i) for i in input().split()]
cnt = 0
for i in range(n):
    for j in range(i):
        if h[i] < h[j]:
            break
    else:
        cnt += 1
print(cnt)
