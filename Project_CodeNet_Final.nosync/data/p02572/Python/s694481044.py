n = int(input())
a = list(map(int, input().strip().split()))
sum = 0
mod = 1000000000+7
for i in a:
    sum += i
    sum %= mod
ans = 0
for i in a:
    sum -= i
    if(sum < 0):
        sum += mod
    ans += sum*i
    ans %= mod
print(ans)
