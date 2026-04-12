n = int(input())
a = list(map(int, input().split()))

a1 = sum(a)**2 
a2 = 0
for i in range(len(a)):
    a2 = (a2 + (a[i]**2)) 

ans = ((a1 - a2) // 2) % 1000000007
print(ans)