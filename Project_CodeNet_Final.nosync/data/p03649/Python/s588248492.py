n = int(input())
a = [int(x) for x in input().split()]
ans = 0
while max(a)>=n:
    b = sum([x//n for x in a])
    ans += b
    a = [x%n+b-x//n for x in a]
print(ans)