N = int(input())
A = list(map(int,input().split()))

square = 0
for i in A:
    square += i*i
ans = ((sum(A)*sum(A) - square) // 2)%(10**9+7)
print(ans)