# ICPC Score Totalizer Software

ans = []

while True:
    n = int(input())
    if n == 0:
        break
    point = [int(input()) for i in range(n)]
    ans.append((sum(point) - max(point) - min(point)) // (n - 2))

for i in range(len(ans)):
    print(ans[i])

