n = int(input())
H = [int(h) for h in input().split()]
ans = 1
for i in range(1, n):
    for j in range(i):
        if H[j] > H[i]: break
        if j == i - 1: ans += 1
print(ans)
