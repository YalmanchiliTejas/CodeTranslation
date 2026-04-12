import itertools
N, M = map(int,input().split())
AB = [0] * M
for i in range(M):
  AB[i] = list(map(int, input().split()))
  
lis = [x for x in range(1, N + 1)] # 1からnまでのリスト
 
permutations_lis = itertools.permutations(lis)# 全ての場合のリストを生成
# 以下出力

ans = 0
for one_case in permutations_lis: 
  #print(one_case) #(1,2,3)など
  if one_case[0] == 1:
    m = 0
  else:
    m = N
  for i in range(N - 1):
    #print(one_case[i])
    path = [one_case[i], one_case[i + 1]]
    path2 = [one_case[i + 1], one_case[i]]
    if path in AB:
      m += 1
    elif path2 in AB:
      m += 1
  if m == N - 1:
    ans += 1
    
print(ans)
  
