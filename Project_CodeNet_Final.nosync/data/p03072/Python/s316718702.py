n = int(input())
a = list(map(int, input().split()))

cnt = 0
pre = 0

for i in a:
    if pre > i:
        pass
    else:
        pre = i
        cnt += 1

print(cnt)