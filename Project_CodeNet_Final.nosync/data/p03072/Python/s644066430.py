n = int(input())
h = [int(s) for s in input().split(' ')]


ans = 0
judge = True
for i in range(n):
    judge = True
    for j in range(i):
        if h[j] > h[i]:
            judge = False
            break
    if judge:
        ans += 1
print(ans)