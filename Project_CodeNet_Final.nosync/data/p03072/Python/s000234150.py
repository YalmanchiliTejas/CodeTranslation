n = int(input())
l = list(map(int,input().split()))
hi = l[0]
cnt = 0
for i in range(1,n):
    if hi <= l[i]:
        cnt += 1
        hi = l[i]
print(cnt+1)
