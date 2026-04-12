n = int(input())
a = list(map(int,input().split()))
s = sum(a) ** 2
b = []
for i in range (n):
    b.append(a[i]**2)
s = (s - sum(b)) // 2
mod = s % (10**9 + 7)
print(mod)


