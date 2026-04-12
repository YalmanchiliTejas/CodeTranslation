n=int(input())
arr = list(map(int,input().split()))

sum1=0
sum2=0

for i in arr:
    sum1+=i
    sum2+=i**2

print(((sum1**2-sum2)//2)%(10**9+7))