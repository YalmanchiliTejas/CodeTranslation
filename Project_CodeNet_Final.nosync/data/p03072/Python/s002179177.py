n = int(input())

li = list(map(int,input().split()))

temp = 0
cnt = 0
for x in li:
    if x >= temp:
        temp = x
        cnt += 1
print(cnt)