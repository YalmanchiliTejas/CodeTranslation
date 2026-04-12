N = int(input())
A = list(map(int,input().split()))
n = len(A)
z = 10 ** 9 + 7
ans = 0

x = sum(A)
x = x ** 2
for i in A:
    y = i * i
    x -= y

x = x // 2
x = x % z
print(x)