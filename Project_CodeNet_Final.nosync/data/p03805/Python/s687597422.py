
from collections import defaultdict
import itertools

def main():
    node_num, edge_num = map(int, input().split())
    data = [list(map(int, input().split())) for i in range(edge_num)]
    edge_dic = defaultdict(set)
    for i in range(edge_num):
        a, b = data[i]
        edge_dic[a].add(b)
        edge_dic[b].add(a)

    ori_list = [i for i in range(2, node_num + 1)]
    ans = 0
    for root in list(itertools.permutations(ori_list, node_num - 1)):
        root = [1] + list(root)
        for i in range(node_num - 1):
            if root[i + 1] not in edge_dic[root[i]]:
                break
        else:
            ans += 1

    print(ans)




if __name__ == '__main__':
    main()
