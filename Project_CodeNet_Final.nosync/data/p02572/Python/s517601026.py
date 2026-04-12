n = int(input())
a = list(map(int, input().split()))
sm = sum(a)
ans = 0
mod = 1000000007
for x in a:
    sm -= x
    ans = (ans + sm*x)%mod
print(ans)
