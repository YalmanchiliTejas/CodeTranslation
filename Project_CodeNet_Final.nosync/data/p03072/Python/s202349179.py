n = int(input())
h = list(map(int, input().split()))

cnt = n
for i in reversed(range(n)):
    for j in reversed(range(i)):
        if h[i] < h[j]:
            cnt-=1
            break
        
print(cnt)