N = int(input())
H = list(map(int, input().split()))

# 各山のたかさを１個ずつみて
# その時点の最大値より高い山が出るたびにカウントアップ
cnt = 1  # H1は必ず1なので
maxHeight = H[0]
for i in range(1, N):
   if H[i] >= maxHeight :
       cnt += 1
       maxHeight = H[i]

print(cnt)