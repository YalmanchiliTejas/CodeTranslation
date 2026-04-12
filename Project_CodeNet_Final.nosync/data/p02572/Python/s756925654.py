n = int(input())
a = list(map(int,input().split()))

ans = 0
s = sum(a)
for i in range(n):
    ans += (s-a[i]) * a[i]
print((ans//2)%1000000007)