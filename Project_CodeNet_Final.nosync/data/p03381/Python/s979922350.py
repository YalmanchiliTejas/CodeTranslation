N = int(input())
X = list(map(int, input().split()))

S = sorted(X)

med_left = S[N//2 - 1]
med_right = S[N//2]

for i in range(N):
  if X[i] <= med_left:
    print(med_right)
  else:
    print(med_left)