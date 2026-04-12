n = int(input())
arr = list(map(int, input().split()))
s = sum(arr)
s = s*s
mod = 10**9 + 7
ind = 0
for i in range(n):
    ind += arr[i]*arr[i]
print(((s-ind)//2)%mod)