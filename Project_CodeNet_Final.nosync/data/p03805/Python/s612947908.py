import numpy as np
N, M = map(int, input().split())

Node = [[] for _ in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    Node[a-1].append(b-1)
    Node[b-1].append(a-1)

# print(Node)
Check = [0]*N
Check[0] = 1
ans = 0

def TreeSearch(x):
    # print('x={}:  '.format(x), end='')
    for i in Node[x]:
        # print('i={} '.format(i), end='')
        if Check[i] == 0:
            Check[i] = 1
            # print('  Check =', Check)
            if np.prod(Check) == 1:
                global ans
                ans += 1
                # print('ans=', ans)
                # print()
            TreeSearch(i)
            Check[i] = 0
            # print('modori from {}:  Check = {}'.format(i, Check))
           
TreeSearch(0)
print(ans)
