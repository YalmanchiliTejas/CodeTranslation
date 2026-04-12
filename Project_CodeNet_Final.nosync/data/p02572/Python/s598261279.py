def readInt():
    return list(map(int, input().split()))

n = int(input())
a = readInt()

# print(n)
# print(a)
b = 0
ans = 0
for i in a:
    i %= 10**9+7 
# print(a)

for i in range(n-1):
    b += a[i]
    ans += a[i+1] * b

ans %= (10**9+7)

print(ans)
