n = int(input())
lst = list(map(int,input().split()))
x = sum(lst)%((10**9 + 7)*2)
y = x**2%((10**9 + 7)*2)
z = 0
for i in range(n):
    z = (z + (lst[i]%((10**9 + 7)*2))**2)%((10**9 + 7)*2)
ans = int((y - z)%((10**9 + 7)*2)/2)
print(ans)
