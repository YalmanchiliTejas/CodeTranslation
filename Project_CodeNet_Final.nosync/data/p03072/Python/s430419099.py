n = int(input())
H = list(map(int, input().split()))
ans = 0
for i in range(n):
    see = True
    for j in range(i):
        if H[j] > H[i]:
            see = False
            break
    if see:
        ans += 1
print(ans)
