#B
n = int(input())
h = list(map(int,input().split()))
cnt = 0
for i in range(len(h)):
    ma = max(h[:i+1])
    if h[i] >= ma:
        cnt += 1
        
print(cnt)