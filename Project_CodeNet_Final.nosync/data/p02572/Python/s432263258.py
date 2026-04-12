N = int(input())
A = list(map(int,input().split()))

B = list(map(lambda x : x**2 , A))
x = sum(A)
y = sum(B)
ans = (x**2 - y) // 2

print(ans%(10**9 + 7))
