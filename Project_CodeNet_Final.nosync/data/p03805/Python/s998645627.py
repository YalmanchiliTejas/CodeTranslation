import sys
input = sys.stdin.readline
import itertools
import math
def main():
    N,M = map(int,input().split())
    root = [[] for _ in range(N)]
    ans = math.factorial(N-1)
    for i in range(M):
        a,b = map(int,input().split())
        root[a-1].append(b-1)
        root[b-1].append(a-1)

    for i in itertools.permutations([j for j in range(1,N)]):
        if i[0] not in root[0]:
            ans -= 1
        else:
            for j in range(N-2):
                if i[j+1] not in root[i[j]]:
                    ans -= 1
                    break

    print(ans)

if __name__ == "__main__":
    main()