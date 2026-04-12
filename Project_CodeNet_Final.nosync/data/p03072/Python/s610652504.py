n = int(input())
lis = list(map(int, input().split()))

tmp = 0
cnt = 0
for i in range(n):
    if tmp <= lis[i]:
        cnt += 1
        tmp = lis[i]
        
print(cnt)