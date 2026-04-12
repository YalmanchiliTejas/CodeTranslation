n = int(input())
lst = list(map(int, input().split()))

ans = 0
summ = sum(lst)
summ_sq = summ**2
for i in range(n):
    ans += lst[i]**2

res = (summ_sq-ans)//2
print(res % ((10**9)+7))
