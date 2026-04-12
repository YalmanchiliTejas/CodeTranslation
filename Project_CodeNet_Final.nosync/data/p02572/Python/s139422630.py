n = int(input())
a = list(map(int,input().split()))
s = sum(a)
x = 0
ans = 0
for i in a:
    ans += i*(s-i-x)
    x += i
    ans %= 1000000007
print(ans)