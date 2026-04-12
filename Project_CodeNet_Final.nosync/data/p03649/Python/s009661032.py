n = int(input())
a = list(map(int, input().split()))

ans = 0
while True:
    tmp = 0
    for i in range(n):
        k = -(-(a[i]+1)//n)-1
        tmp += k
        a[i] -= k*n
        a[i] -= k
    for i in range(n):
        a[i] += tmp
    if not tmp:
        break
    ans += tmp

print(ans)