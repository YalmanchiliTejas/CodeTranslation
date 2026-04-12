n = int(input())
h = list(map(int, input().split()))
l = []
cnt = 0

for i in range(n):
    l.append(h[i])
    if h[i] == max(l):
        cnt += 1
        
print(cnt)