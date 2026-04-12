n = int(input())
a = [int(i) for i in input().split()]
max = 0
ans = 0
for i in range(n):
    if a[i] >= max:
        ans+=1
        max = a[i]
print(ans)