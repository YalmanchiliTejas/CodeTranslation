MOD = 1000000007

n=int(input())
a=list(map(int,input().split()))

array_sum = 0
for i in range(0, n, 1): 
    array_sum += a[i]

array_sum_square = pow(array_sum,2)

individual_square_sum = 0
for i in range(0, n, 1): 
    individual_square_sum+= pow(a[i],2)

ans=(array_sum_square - individual_square_sum) //2
print(ans%MOD)