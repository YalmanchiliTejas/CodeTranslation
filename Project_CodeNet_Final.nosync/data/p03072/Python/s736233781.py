n = int(input())
h = list(map(int, input().split()))
cnt = 1
for i in range(1, len(h)):
    cnt += 1
    for n in range(i):
        if h[i] < h[n]:
            cnt -= 1
            break
            
print(cnt)