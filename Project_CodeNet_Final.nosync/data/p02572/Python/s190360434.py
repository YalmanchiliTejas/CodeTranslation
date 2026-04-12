N = int(input())
A = [int(x) for x in input().split()]

gokei = sum(A) ** 2
for i in range(len(A)):
    gokei -= A[i] * A[i]
gokei = gokei // 2
ans = gokei % 1000000007
print(ans)
