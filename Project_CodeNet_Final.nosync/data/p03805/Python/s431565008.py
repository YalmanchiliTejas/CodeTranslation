import itertools

N, M = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(M)]

def is_path(seq):
    for idx in range(len(seq)):
        if idx == 0:
            if [1, seq[idx]] not in edges and [seq[idx], 1] not in edges:
                return False
        else:
            if [seq[idx-1], seq[idx]] not in edges and [seq[idx], seq[idx-1]] not in edges:
                return False
    return True
        
num = 0
for seq in list(itertools.permutations(list(range(2, N+1)))):
    if is_path(seq):
        num += 1
print(num)