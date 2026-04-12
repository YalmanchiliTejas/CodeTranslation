n = int(input())
arr = list(map(int, input().split()))
high = 0
cnt = 0
for i in arr:
    if high <= i:
        cnt +=  1
        high = i
print(cnt)