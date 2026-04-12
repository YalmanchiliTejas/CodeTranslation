n = int(input())
hs = [int(h) for h in input().strip().split()]

# print(hs)
max = 0
ans = 0
for i in range(n):
    if hs[i] >= max:
        ans +=1
        max = hs[i]

print(ans)