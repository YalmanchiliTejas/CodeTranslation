n=int(input())
a=[int(x) for x in input().split()]

a_sum=sum(a)
a_sq=[x**2 for x in a]
a_sum_sq=sum(a_sq)
ans=(a_sum**2-a_sum_sq)//2
ans%=10**9+7
print(ans)