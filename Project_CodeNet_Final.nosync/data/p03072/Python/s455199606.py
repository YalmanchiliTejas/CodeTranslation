N = int(input())
list1 = []
list1 = list(map(int, input().split()))
max1 = list1[0]
ans = 0
for i in range(N):
    if list1[i] >= max1:
        ans += 1
        max1 = list1[i]

print(ans)