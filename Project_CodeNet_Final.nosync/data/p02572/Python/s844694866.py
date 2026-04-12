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

s = sum(a)
s2 = sum(map(lambda x:x**2,a))

ans = (s**2 - s2 ) // 2

ans %= (10**9+7)

print(ans)
