n = int(input())
p = list(map(int, input().split()))
count = 1

for num in range(1,n):
    if max(p[:num]) <= p[num]:
        count += 1
print(count)
