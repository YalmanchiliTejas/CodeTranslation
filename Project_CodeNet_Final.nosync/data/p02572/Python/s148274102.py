p = 10**9+7
n = int(input().rstrip())
a_ls = list(map(int, input().rstrip().split(" ")))
a_ls = [a%p for a in a_ls]
a2_ls = [(a**2)%p for a in a_ls]
a_sum_sq = ((sum(a_ls))**2)%p
a2_sum = sum(a2_ls)%p
ans = (a_sum_sq-a2_sum)%p
if ans%2 != 0:
  ans += p
ans //= 2
print(ans)