N, M = list(map(int,input().split()))
adj = []
visit = []

def DFS(p):
  count = 0
  if all(visit):
    return 1
  for n in adj[p]:
    if visit[n] == 0:
      visit[n] = 1
      count += DFS(n)
      visit[n] = 0
  return count

def main():
  for n in range(N):
    adj.append([])
    visit.append(0)
  for m in range(M):
    i, j = list(map(int,input().split()))
    adj[i-1].append(j-1)
    adj[j-1].append(i-1)
  visit[0] = 1
  return DFS(0)

print(main())