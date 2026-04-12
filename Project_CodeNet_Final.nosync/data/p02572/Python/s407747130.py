n = int(input())
nums = list(map(int, input().split()))
ans = 0
mod = 10**9 + 7
pres = [0]
for i in nums:
    pres.append(pres[-1] + i)
for i in range(n):
    temp = nums[i] * (pres[n] - pres[i+1])
    ans += temp
    ans %= mod
print(ans)
