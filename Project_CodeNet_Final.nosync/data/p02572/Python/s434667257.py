n = input()
a = list(map(int, input().split()))
b = sum(a)
sum = 0

for i in range(len(a)):
    b -= a[i]
    sum += a[i]*b   

print(sum%(10**9+7))