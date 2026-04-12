import itertools
import math
N,M = (int(T) for T in input().split())
List = [[] for TM in range(0,M)]
for TM in range(0,M):
    List[TM] = [int(T) for T in input().split()]
    
Node = [[] for TN in range(0,N+1)]
for TM in range(0,M):
    Node[List[TM][0]].append(List[TM][1])
    Node[List[TM][1]].append(List[TM][0])
    
Count = math.factorial(N-1)
for TI in itertools.permutations(range(2,N+1)):
    Root = (1,)+TI
    for TR in range(0,N-1):
        if Root[TR+1] not in Node[Root[TR]]:
            Count -= 1
            break
print(Count)