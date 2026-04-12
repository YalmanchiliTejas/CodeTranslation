#124
n = int(input())
h = list(map(int, input().split()))

res = 0
for i in range(n):
    jud = 1==1
    for j in range(0,i):
        if h[i] < h[j]:
            jud = 1==0
            break
    if jud:
        res += 1
print(res)