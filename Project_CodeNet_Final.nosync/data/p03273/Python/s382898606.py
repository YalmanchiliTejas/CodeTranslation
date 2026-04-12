n,m = map(int,input().split())
l = [list(input()) for i in range(n)]
gyou = []
retsu = []
count = 0
for i in range(n):
    a = "."
    count = 0
    for j in range(m):
        if a == l[i][j]:
            count += 1
    if count != m:
        gyou.append(i)
for i in range(m):
    a = "."
    count = 0
    for j in range(n):
        if a == l[j][i]:
            count += 1
    if count != n:
        retsu.append(i)

for i in range(n):
    if i in gyou:
        for j in range(m):
            if j in retsu:
                if j == retsu[-1]:
                    print(l[i][j])
                else:
                    print(l[i][j],end="")


