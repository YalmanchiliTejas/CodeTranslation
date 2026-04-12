N = int(input())
A = [int(x) for x in input().split()]

s1 = sum(A) ** 2
s2 = sum([x ** 2 for x in A])
ans = (s1 - s2) // 2 % 1000000007
print(ans)
