import sys
from itertools import permutations
sys.setrecursionlimit(1000000) # 再帰上限を増やす

def main():
    input = sys.stdin.readline  # 文字列に対してinputした場合は、rstripするのを忘れずに！
    N, M = map(int, input().rstrip().split())
    path_list = []
    for _ in range(M):
        a, b = map(int, input().rstrip().split())
        path_list.append((a-1, b-1))
        path_list.append((b-1, a-1))

    count = 0
    for path in permutations(range(1, N)):
        now_posi = 0
        for next_posi in path:
            if (now_posi, next_posi) not in path_list:
                break
            now_posi = next_posi
        else:
            count += 1
    print(count)

if __name__ == '__main__':
    main()