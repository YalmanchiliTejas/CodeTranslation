N = int(input())
H = list(map(int,input().split()))
K = H[0]
L = -1
ans = 1
for i in range(0,N):
    if L<= H[i]:
        L = H[i]
        ans += 1
    else:
        ans += 0
print(ans-1)
