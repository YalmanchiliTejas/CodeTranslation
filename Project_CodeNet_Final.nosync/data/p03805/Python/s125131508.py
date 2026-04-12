#隣接行列を書く
n,m = map(int,input().split())
ll = [[0]*n for _ in [0]*n]
for i in range(m):
  a,b = map(int,input().split())
  ll[a-1][b-1] = 1
  ll[b-1][a-1] = 1
#初期は1番目の点のみ訪問済み。かつ現在地は0番目
visit = [1]+[0]*(n-1)
place = 0
ans=0
#探索用関数
def search(visit,place):
  ans = 0
  if visit == [1]*n:
    return 1
  for i in range(n):
    if visit[i] == 0 and ll[place][i] == 1:
      tmpvisit = visit.copy()
      tmpvisit[i] = 1
      ans += search(tmpvisit,i)
  return ans
ans = search(visit,place)
print(ans)