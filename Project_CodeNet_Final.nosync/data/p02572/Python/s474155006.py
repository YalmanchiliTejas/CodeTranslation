n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
sq_s = 0
for i in range(len(arr)):
    sq_s += arr[i]*arr[i]
m = 1000000007
print(((s**2 - sq_s)//2)%m)
