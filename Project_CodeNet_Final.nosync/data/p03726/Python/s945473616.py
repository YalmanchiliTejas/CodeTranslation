import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    N = int(input())
    X = [[] for _ in range(N)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        X[a-1].append(b-1)
        X[b-1].append(a-1)

    Q = [0]
    P = [-1] * N
    R = []
    while Q:
        i = Q.pop()
        R.append(i)
        for j in X[i]:
            P[j] = i
            X[j].remove(i)
            Q.append(j)
    
    node_type = [0] * N # 1: Leaf etc. 2: Node with a leaf child
    for i in R[::-1]:
        t = sum([1 if node_type[j] == 1 else 0 for j in X[i]])
        if t > 1:
            return 1
        if t:
            node_type[i] = 2
        
        t = sum([1 if node_type[j] <= 1 else 0 for j in X[i]])
        if t == 0:
            node_type[i] = 1
    
    return 1 if node_type[0] == 1 else 0

print("First" if main() else "Second")