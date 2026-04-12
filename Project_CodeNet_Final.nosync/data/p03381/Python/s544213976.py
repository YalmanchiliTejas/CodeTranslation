N = int(input())
X = list(map(int, input().split()))
sorted_X = sorted(X)
median_index = N//2
ans1 = sorted_X[median_index]
ans2 = sorted_X[median_index-1]

for x in X:
  if ans1 > x:
    print(ans1)
  else:
    print(ans2)
