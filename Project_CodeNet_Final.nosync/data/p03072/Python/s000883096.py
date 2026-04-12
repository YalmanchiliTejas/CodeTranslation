n=int(input())
h=list(map(int, input().split())) 
max_h = 0
cnt = 0
for i in range(n):
    if h[i] >= max_h:
        cnt += 1
        max_h = h[i]
print(cnt)