import sys
from collections import deque, defaultdict

input = sys.stdin.readline


class AtCoder:
    def main(self):
        N, M = map(int, input().split())
        edges = defaultdict(set)
        for _ in range(M):
            a, b = map(int, input().split())
            edges[a].add(b)
            edges[b].add(a)

        deq = deque()
        deq.append((1, 1, {1}))

        ans = 0
        while deq:
            node = deq.popleft()
            node_num = node[0]
            cnt = node[1]
            already = node[2]

            if cnt == N:
                ans += 1
                continue

            already.add(node_num)

            for n in edges[node_num]:
                if n not in already:
                    deq.append((n, cnt + 1, already.copy()))

        print(ans)


# Run main
if __name__ == '__main__':
    AtCoder().main()
