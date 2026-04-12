n = int(input())
h = list(map(int, input().split()))

h.reverse()
ans = 0
flag = 0
for i in range(n):
    flag = 1
    for j in range(i, n):
        if h[i] < h[j]:
            flag = 0
            break

    if flag == 1:
        ans += 1

print(ans)
