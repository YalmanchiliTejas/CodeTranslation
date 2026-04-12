a, b, c, x, y = map(int, input().split())
n_a = x
n_b = y
n_c = 2

ans = a * n_a + b * n_b
while ans > a * max(n_a - 1, 0) + b * max(n_b - 1, 0) + c * n_c:
    ans = a * max(n_a - 1, 0) + b * max(n_b - 1, 0) + c * n_c
    n_a -= 1
    n_b -= 1
    n_c += 2
    
print(ans)