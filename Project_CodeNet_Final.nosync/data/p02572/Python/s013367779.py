n = int(input())
a = list(map(int, input().split()))
prod_sum = 0
sum_arr = [0]*n
sum_arr[n-1] = a[n-1]
for i in range(n-2, -1, -1):
    sum_arr[i] = sum_arr[i+1] + a[i]
for i in range(n-1):
        prod_sum += a[i]*sum_arr[i+1]
print(prod_sum%(10**9+7))
