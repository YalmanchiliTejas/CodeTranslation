n=int(input())
arr=list(map(int,input().split()))
arr_sum = 0
mod = 10**9 + 7
for i in range(0, n, 1): 
    arr_sum = arr_sum + arr[i] 

temp = arr_sum * arr_sum  
temp1 = 0

for i in range(0, n, 1): 
    temp1 += arr[i] * arr[i] 
ans=((temp - temp1)//2)%mod
print(ans)