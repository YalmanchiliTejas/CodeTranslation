N = int(input())
M = input().split(' ')
A = [int(x) for x in M]

M = int(1e9+7)

s = 0
for a in A:
    s += a

ans = 0
for a in A:
    ans += a * (s-a)

ans //= 2
print(int(ans % M))
