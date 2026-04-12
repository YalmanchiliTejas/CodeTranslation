n = int(input())
arr = list(map(int,input().split()))
ans = 0
tmp = 0

for i in range(n-1):
    tmp += arr[i]%1000000007
    ans += tmp*arr[i+1] % 1000000007

print(ans%1000000007)
