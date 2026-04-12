l = int(input())
num = input().split(' ')
num = [int(i) for i in num]
ans = 0
s = sum(num)
for i in range(l):
    s -= num[i]
    ans += num[i] * s
print(ans%(10**9+7))