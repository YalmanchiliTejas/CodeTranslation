n = int(input())
a = list(map(int, input().split()))

a.sort()
ans = 0
while a[-1] >= n:
    k = -(-(a[-1]+1)//n)-1
    ans += k
    for i in range(n-1):
        a[i] += k
    a[-1] -= n*k
    a.sort()

print(ans)