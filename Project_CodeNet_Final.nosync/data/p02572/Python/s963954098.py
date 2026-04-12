d = 1000000007
n = int(input())
a = list(map(int, input().split()))
summation = sum(a)
diagonal = 0
for i in range(len(a)):
        diagonal += a[i] ** 2 
ans = (((summation  ** 2) - diagonal) // 2) % d
print(ans)