n = int(input())
h = list(map(int,input().split()))
cnt = 0
for i in range(n):
    #print(h[:i])
    if max(h[:i+1])==h[i]:
        cnt += 1
print(cnt)