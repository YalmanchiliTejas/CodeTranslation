n = int(input())
h = list(map(int,input().split()))
ans = 0
for i in range(n):
    check = True
    for j in range(i+1):
        if h[i] < h[j]:check = False;break
    if check:ans += 1
print(ans)