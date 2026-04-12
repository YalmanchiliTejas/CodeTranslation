n = int(input())
h = list(map(int,input().split()))
ans = n

for i in range(1,n):
    for j in range(i):
        if h[i] < h[j]:
            ans -= 1
            break

print(ans)
