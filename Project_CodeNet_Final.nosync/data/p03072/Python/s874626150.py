n = int(input())
h = [int(n) for n in input().split()]

max = h[0]
ans = 0

for i in h:
    if max<=i:
        ans += 1
        max = i
print(ans)