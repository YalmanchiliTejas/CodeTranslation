n = int(input())
m = list(map(int, input().split()))
maxm = 0
ryokan = 0
for i in range(n):
    if maxm <= m[i]:
        maxm = m[i]
        ryokan += 1
print(ryokan)