N = int(input())
mt = list(map(int, input().split()))

cnt = 0
for i in range(N):
    if mt[i] == max(mt[:i+1]):
        cnt += 1
print(cnt)