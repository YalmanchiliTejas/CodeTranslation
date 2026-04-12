
def dfs(node, paths, visited, n):
  # 全て訪問済みだったら全部を訪問できる経路として1を返す
  if not False in visited:
    return 1

  count = 0

  for nn in paths[node]:
    # 既に訪問済みなら処理をしない
    if(visited[nn]):
      continue

    visited[nn] = True
    count += dfs(nn, paths, visited, n)
    visited[nn] = False

  return count

def main():
  N, M = list(map(int, input().split()))
  paths = [[] for i in range(N)]
  visited = [False] * N

  for i in range(M):
    a, b = list(map(int, input().split()))
    paths[a-1].append(b-1)
    paths[b-1].append(a-1)

  visited[0] = True
  print(dfs(0, paths, visited, N))


if __name__ == "__main__":
    main()