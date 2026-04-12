n = int(input())
l = list(map(int,input().split()))
ans = 0
sum_n = [0]*n
sum_n[0] = l[0]
sumall = sum(l)
for i in range(1,n):
    sum_n[i] = sum_n[i-1] + l[i]
for i in range(n):
    ans += ((l[i]*(sumall-sum_n[i]))%1000000007)
print(ans%1000000007)