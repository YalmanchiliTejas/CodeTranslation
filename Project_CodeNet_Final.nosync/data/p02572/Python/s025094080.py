N = int(input())
A = [int(x) for x in input().split()]
key = 1000000007
sum = 0
sum2 = 0
for i in range(N):
    sum += A[i]
    #if sum >= key:
     #   sum %= key

for i in range(N):
    sum2 += A[i]**2
    #if sum2 >= key:
     #   sum2 %= key
        
ans = (sum*sum - sum2)//2%key
print(ans)
    