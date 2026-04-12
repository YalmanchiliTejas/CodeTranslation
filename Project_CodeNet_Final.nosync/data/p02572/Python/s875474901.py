N = int(input())
A = list(map(int, input().split()))

P = 10**9 + 7

ans = 0
tmp = 0
for num in A:
    tmp += num
    tmp %= P
for num in A:
    ans += (num*tmp)%P
    ans -= pow(num, 2, P)
    ans %= P

ans = ans * pow(2, P-2, P)
ans %= P
print(ans)

