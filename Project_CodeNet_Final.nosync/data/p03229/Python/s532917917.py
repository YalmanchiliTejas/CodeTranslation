n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
p1 = []
p2 = []
for i in range(n):
    x = 2
    if i == 0 or i == n-1:
        x = 1
    if i % 2 == 0:
        p1.append(x)
        p2.append(-x)
    else:
        p1.append(-x)
        p2.append(x)
p1.sort()
p2.sort()

ans1 = 0
ans2 = 0
for i in range(n):
    ans1 += a[i]*p1[i]
    ans2 += a[i]*p2[i]

print(max(ans1, ans2))