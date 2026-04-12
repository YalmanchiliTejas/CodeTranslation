n = int(input())
a = list(map(int,input().split()))
pfx = 0
ans = 0
mod = int(1e9) + 7
for i in a:
    ans = (ans + pfx * i) % mod
    pfx += i
print(ans)