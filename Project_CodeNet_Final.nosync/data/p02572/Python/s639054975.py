n = int(input())
sz = [int(x) for x in input().split(" ")]

ans = sum(sz)*sum(sz)

for i in sz :
    ans -= i*i

ans //= 2
ans %= (10**9+7)

print(int(ans))