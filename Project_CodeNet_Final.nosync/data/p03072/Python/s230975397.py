N = int(input())
H = list(map(int,input().split()))

ans = 0

for i in range(1,N):
    tmp = H[:i+1]
    if H[i] == max(tmp):
        ans += 1

print(ans+1)