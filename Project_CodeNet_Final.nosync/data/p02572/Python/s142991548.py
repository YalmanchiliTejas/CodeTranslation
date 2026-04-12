n = int(input())
*arr, = map(int, input().split())
modulo = 10 ** 9 + 7
p = arr.copy()
p.append(0)
for i in range(len(p) - 2, -1, -1):
    p[i] = (p[i] + p[i + 1]) % modulo

ans = 0
for i in range(n):
    ans += arr[i] * p[i + 1]
    ans %= modulo
print(ans)



