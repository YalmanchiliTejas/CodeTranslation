N = int(input())
l = list(map(int,input().split()))

cnt = max = 0
for i in range(N):
    if l[i] >= max:
        max = l[i]
        cnt += 1

print(cnt)