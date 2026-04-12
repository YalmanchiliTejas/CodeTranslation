n = int(input())
hs = input().split()
count = 1
maxh = 0
for i in range(1,n):
    maxh = max(maxh, int(hs[i-1]))
    if int(hs[i])>=maxh:
        count += 1
print(count)