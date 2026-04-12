N = int(input())
H = list(map(int, input().split()))
cnt = 0
for i in range(N):
    if H[i] >= max(H[:i+1]):
        cnt+=1
    else:
        pass
print(cnt)