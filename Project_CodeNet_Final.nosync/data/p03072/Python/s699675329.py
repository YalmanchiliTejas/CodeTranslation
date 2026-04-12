n = int(input())
h = list(map(int, input().split()))
cnt = 0

for i in range(1,n+1):
    if h[i-1] == max(h[:i]):
        cnt +=1
print(cnt)