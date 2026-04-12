import itertools
import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

def main():
    N, M, *ab = map(int, read().split())
    E = [[] for _ in range(N+1)]

    for a, b in zip(*[iter(ab)] * 2):
        E[a].append(b)
        E[b].append(a)
    
    ans = 0
    fact_p = itertools.permutations(range(2,N+1))
    for p in fact_p:
        par = 1
        flag = True
        for i in p:
            if par not in E[i]:
                flag = False
                break
            par = i
            
        if flag:
            ans += 1
    
    print(ans)


if __name__ == "__main__":
    main()
