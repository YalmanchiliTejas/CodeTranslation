n = int(input())
a = list(map(int,input().split()))
sum_a = sum(a)
ans = 0

for i in a:
    sum_a -= i
    ans += i * sum_a
    ans %= 10**9 + 7
    
print(ans)