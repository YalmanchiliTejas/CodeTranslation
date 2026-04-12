N = int(input())
a = list(map(int,input().split()))
a_s = sum(a)
mod = 10**9+7
s = 0
for i in range(N-1):
    b = a[i]
    a_s -= b
    s += b*(a_s)
    s %= mod
print(s)