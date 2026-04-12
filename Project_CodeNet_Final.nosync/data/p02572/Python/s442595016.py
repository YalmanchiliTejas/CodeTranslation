n = int(input())
v = [int(x) for x in input().split()]
suma, ans = sum(v), 0
for i in range(n - 1):
    suma -= v[i];
    ans += (suma * v[i])
print(ans % 1000000007)
    
