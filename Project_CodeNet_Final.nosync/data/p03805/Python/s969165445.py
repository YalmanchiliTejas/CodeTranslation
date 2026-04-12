# time complexity: O(N*N!) (本当はO(N!))
# space complexity: O(M)
from itertools import permutations


N, M = [int(elem) for elem in input().split(' ')]
edge_set = set([tuple([int(elem) - 1 for elem in input().split(' ')]) for _ in range(M)])
edge_set |= {(edge[1], edge[0]) for edge in edge_set}
assert len(edge_set) == 2 * M

num_possible_path = 0
for permutation in permutations(range(1, N), N-1):
    permutation = [0] + list(permutation)
    for i in range(N - 1):
        if tuple(permutation[i:i+2]) not in edge_set:
            break
        else:
            continue
    else:
        num_possible_path += 1

print(num_possible_path)
