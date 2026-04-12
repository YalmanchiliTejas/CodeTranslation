import numpy as np
import copy


def visit(next_node, visited_nodes, adj_mat):
    assert next_node not in visited_nodes

    if len(visited_nodes) + 1 == len(adj_mat):
        # Visited all nodes
        return 1
    else:
        adj_nodes = np.argwhere(adj_mat[next_node].flatten() == 1)
        if len(adj_nodes) == 0:
            # Failed
            return 0
        else:
            n_paths = 0
            for adj_node in adj_nodes:
                if adj_node not in visited_nodes:
                    n_paths += visit(adj_node, visited_nodes +
                                     [next_node, ], adj_mat)
                else:
                    continue
            return n_paths


def main():
    N, M = map(int, input().split())
    adj_mat = np.zeros((N, N), dtype=np.int32)
    for _ in range(M):
        a, b = map(int, input().split())
        adj_mat[a-1][b-1] = 1
        adj_mat[b-1][a-1] = 1
    assert np.sum(adj_mat) == M * 2

    next_nodes = np.argwhere(adj_mat[0].flatten() == 1)
    n_paths = np.sum([visit(next_node, [0, ], adj_mat)
                      for next_node in next_nodes])

    print(n_paths)


if __name__ == '__main__':
    main()
