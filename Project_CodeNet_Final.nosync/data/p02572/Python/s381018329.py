MOD = 10**9+7

n = int(input())
a = list(map(int, input().split()))

arr = [a[-1]]
for i in range(len(a)-2,-1,-1):
    arr += [arr[-1] + a[i]]

arr.reverse()
ans = 0
for i in range(len(a)-1):
    
    ans += (a[i] * (arr[i]-a[i]))%MOD
   
print(ans%MOD)