n = int(input())
v = list(map(int,input().split()))
min0 = v[0]
cnt = 0
for i in range(n):
    if v[i] >= min0:
        cnt += 1
        min0 = v[i]
print(cnt)