n = int(input())
a = list(map(int,input().split()))
res = 0
for i in range(n):
    res += all(j <= a[i] for j in a[:i])
print(res)
