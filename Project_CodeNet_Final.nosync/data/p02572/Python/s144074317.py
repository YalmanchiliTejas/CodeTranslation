def readInt():
    return list(map(int, input().split()))

n = int(input())
a = readInt()
b = 0
ans = 0

for i in a:
    b += i ** 2

# print(sum(a))
ans = ((sum(a) ** 2 - b) // 2) % (10 ** 9 + 7)
print(ans)
