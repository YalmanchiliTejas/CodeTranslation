n = int(input())
lis = list(map(int,input().split()))
li = [0]
for num in lis:
    li.append(li[-1] + num)
ans = 0
mod = 10 ** 9 + 7
for i in range(n):
    ans += (lis[i] * li[i]) % mod
    ans %= mod
print(ans)