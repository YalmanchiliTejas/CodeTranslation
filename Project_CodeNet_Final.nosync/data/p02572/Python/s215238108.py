# import decimal
n = int(input())
a = list(map(int, input().split())) 

first = a[0]

ans = first*a[1]

for i in range(1, n-1):
    first += a[i]
    ans += first*a[i+1]

print(ans%(10**9+7))