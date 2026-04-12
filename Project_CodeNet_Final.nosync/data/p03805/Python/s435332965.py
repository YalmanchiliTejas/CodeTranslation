from itertools import permutations
from collections import deque

def main():
    N, M = map(int, input().split())
    edge = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        edge[a].append(b)
        edge[b].append(a)
    cnt = 0
    for patterns in permutations(range(1,N)):
        pattern = [0] + list(patterns)
        Q = deque(pattern)
        while Q:
            s = Q.popleft()
            if Q[0] in edge[s]:
                if len(Q) == 1:
                    Q.popleft()
                    break
                else:
                    continue
            else:
                break
        if not Q:
            cnt += 1
    
    print(cnt)
if __name__ == "__main__":
    main()