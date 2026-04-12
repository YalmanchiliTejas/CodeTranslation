n = int(input())
high = [int(i) for i in input().split()]
ans = 0
max = 0
for i in range(n):
    if max<=high[i]:
        ans += 1
        max = high[i]

print(ans)
