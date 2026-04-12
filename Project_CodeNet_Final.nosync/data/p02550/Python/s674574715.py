from collections import deque
N,X,M = map(int, input().split())

nodeset = set()
nodeset.add(X)

nodeq = deque()
nodeq.append(X)

is_finish = False
s,e = 0, N
for i in range(N-1):
    X = (X*X) % M
    if X in nodeset:
        is_finish = True
        
        for p, start in enumerate(nodeq):
            if X == start:
                s = p
                break
        # ループ終了
        break

    nodeq.append(X)
    nodeset.add(X)

nodelist = list(nodeq)
if is_finish:
    loop_size = len(nodelist) - s # 繰り返し部分のサイズ
    loop_cnt = (N - s) //loop_size # 繰り返し回数
    loop_sum = sum(nodelist[s:]) # 繰り返し部分の和
    alpha = (N - s) % loop_size # すべてやったあとの繰り返し部分の余り
    result = sum(nodelist[:s]) + loop_cnt * loop_sum + sum(nodelist[s:s+alpha])
    print(result)
else:
    print(sum(nodelist))

