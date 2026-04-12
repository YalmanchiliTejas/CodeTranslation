n = int(input())
a_lst = list(map(int, input().split()))

a_lst.reverse()
tmp = a_lst[0]
lst = []
for i in range(1, n):
    lst.append(tmp)
    tmp += a_lst[i]
    tmp %= (10 ** 9 + 7)
lst.reverse()
a_lst.reverse()

ans = 0
for i in range(n - 1):
    ans += (a_lst[i] * lst[i]) % (10 ** 9 + 7)
ans %= (10 ** 9 + 7)
print(ans)