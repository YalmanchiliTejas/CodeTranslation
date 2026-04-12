# 入力
N = int(input())
Hi = input().split()
count = 0
H0 = 0
# 判定
for i in range(N):
    if int(Hi[i]) >= int(H0):
        count += 1
        H0 = Hi[i]
print(count)