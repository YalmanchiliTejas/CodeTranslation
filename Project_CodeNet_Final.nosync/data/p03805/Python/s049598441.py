from itertools import permutations
def solve(N,C):
    node = [i for i in range(1,N+1)]
    lis = list(permutations(node))
    ans = 0
    for v in lis:
        flag = 0
        if v[0] != 1:
            continue
        for i in range(N-1):
            if (v[i],v[i+1]) in C:
                continue
            else:
                flag += 1
        if flag == 0:
            ans += 1
    return ans


def main():
    N,M = map(int,input().split(" "))
    C = set([])
    for _ in range(M):
        a,b = map(int,input().split(" "))
        C.add((a,b))
        C.add((b,a))
    print(solve(N,C))

if __name__ == "__main__":
    main()