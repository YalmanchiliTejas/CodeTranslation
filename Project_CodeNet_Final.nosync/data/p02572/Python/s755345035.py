ans = 0
N = int(input())
array = list(map(int, input().split()))
x = sum(array)
y = 0
for i in range(N):
  y += array[i]**2

ans = x**2 -y
print((ans//2)%(10**9+7))