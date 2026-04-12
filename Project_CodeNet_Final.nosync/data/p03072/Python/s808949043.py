n = int(input())
h = list(map(int,input().split()))
count = 0
ans = 0
sum_h = 0

for i in range(1,n):
    for j in range(i):
        if h[j] > h[i]:
            break
        if j == i - 1:
            ans += 1
print(ans+1)
    