n = int(input())
li = list(map(int,input().split()))
cnt = 0
high = 0

for i in range(n):
    if li[i] >= high:
        cnt += 1
        high = li[i]
print(cnt)