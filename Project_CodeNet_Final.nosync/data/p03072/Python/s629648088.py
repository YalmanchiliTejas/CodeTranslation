n = int(input())
h = list(map(int, input().split()))
a = 1
m = h[0]
# 西から最も高い場所にある旅館であれば、海を眺めることが出来る。
for i in range(1, n):
    m = max(h[i-1], m)
    if m <= h[i]:
        a += 1
print(a)
