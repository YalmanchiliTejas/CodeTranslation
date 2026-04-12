N = int(input())
A = [int(x) for x in input().split()]
sumA = sum(A)
ans = sum(a*(sumA-a) for a in A) //2 %1000000007
print(ans)

