#python3
from itertools import permutations

def main():
    n, m = map(int, input().split())
    edge = set()
    for _ in range(m):
        a, b = map(int, input().split())
        edge.add((a-1, b-1))
        edge.add((b-1, a-1))
    
    node = []
    for i in range(n):
        node.append(i)
    cnt = 0
    for p in permutations(node):
        if p[0] == 0:
            f = True
            for j in range(n-1): 
                if (p[j], p[j+1]) not in edge:
                    f = False
            if f:
                cnt += 1 
    print(cnt)
main()
