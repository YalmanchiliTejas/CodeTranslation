from copy import deepcopy as dcopy
def main():
    global count,N,M,edges,stack
    N, M = map(int, input().split())
    edges = [[0]*N for n in range(N)]
    for m in range(M):
        a,b = map(lambda x:int(x)-1,input().split())
        edges[a][b] = 1
        edges[b][a] = 1

    count = 0
    stack = [[[0], [0]]]
    while len(stack) != 0:
        tansaku = stack.pop()
        next_list = [n for n,v in enumerate(edges[tansaku[0][-1]]) if v == 1]
        search(tansaku, next_list)
    print(count)

def search(tansaku, next_list):
    global count, stack
    for node in next_list:
        tmp_tansaku = dcopy(tansaku)
        tmp_node = tmp_tansaku[0]
        houmonzumi = tmp_tansaku[1]
        if node in houmonzumi:
            pass
        else:
            houmonzumi.append(node)
            if len(houmonzumi) == N:
                count += 1
            else:
                tmp_node.append(node)
                stack.append([tmp_node, houmonzumi])

if __name__ == "__main__":# {{{
    try:
        import test
        test.test()
    except:
        main()# }}}
