n = int(input())
p = list(map(int,input().split()))
count = 0
for i in range(n):
    if i == 0 or max_ <= p[i]:
        max_ = p[i]
        count += 1
print(count)