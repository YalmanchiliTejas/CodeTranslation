N = int(input())
X = list(map(int,input().split()))
Y = sorted(X)
ans1 = Y[N//2-1]#小さいほう
ans2 = Y[N//2]#大きいほう
for i in range(N):
  if X[i] <= ans1: print(ans2)
  else: print(ans1)