n = int(input())
a = list(map(int, input().split()))
s = sum(a)
ans = 0
mod = pow(10, 9) + 7
for i in a:
    s -= i
    ans = (ans + s * i) % mod
print(ans)