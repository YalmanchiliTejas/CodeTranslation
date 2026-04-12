from itertools import accumulate
N = int(input())
A_list = list(map(int,input().split()))
B_list = A_list[::-1]
C_list = list(accumulate(B_list))
D_list = C_list[::-1]
cnt = 0
for i in range(1,N):
    cnt += (A_list[i-1] * D_list[i]) % (10**9 + 7)

    if cnt >= (10**9 + 7):
        cnt -= (10**9 + 7)
print(cnt)