import itertools
N,M=map(int,input().split())
grid = []
for i in range(N):
    array = []
    while len(array) < N:
      array.append(0)
    grid.append(array)
for i in range(M):
    s,t=map(int,input().split())
    grid[s-1][t-1] = 1
    grid[t-1][s-1] = 1
i = 1
lis = []
while i <= N:
  lis.append(i)
  i += 1
ans = 0
for nums in itertools.permutations(lis):
    if nums[0]!=1:
      pass
    else:
      k = 0
      flag = 0
      while k < N-1:
        if grid[nums[k]-1][nums[k+1]-1] == 1:
          pass
        else:
          flag = 1
        k += 1
      if flag == 0:
        ans += 1
print(ans)