N = int(input())
Alist = list(map(int,input().split()))
sum1 = sum(Alist)
ans  = 0 
for i in range(N):
    sum1 -= Alist[i]
    ans += sum1 * Alist[i]
    ans %= 10**9+7
print(ans)