from collections import defaultdict
import queue

if __name__ == "__main__":
    inp = [int(i) for i in input().split()]
    N = inp[0]
    M = inp[1]
    adjs = defaultdict(lambda: [])
    for i in range(M):
        a, b = [int(i) for i in input().split()]
        adjs[a].append(b)
        adjs[b].append(a)
    
    q = queue.Queue()
    q.put([1])
    n = 0
    while True:
        if q.empty(): break
        p = q.get()
        if len(p) == N:
            n += 1
        else:
            for i in adjs[p[-1]]:
                if i not in p:
                    pp = p.copy()
                    pp.append(i)
                    q.put(pp)
    print(n)