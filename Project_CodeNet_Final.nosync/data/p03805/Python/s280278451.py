from collections import defaultdict
n, m = map(lambda x: int(x), input().split())

links = defaultdict(set)

for _ in range(m):
    a, b = map(lambda x: int(x), input().split())
    links[a].add(b)
    links[b].add(a)
    
path_counter = 0
    
def path_patterns_number(current_node, remaining_nodes):#, remaining_links):
    if len(remaining_nodes) == 0:
        return 1
    
    patterns = 0
    
    for next_node in (links[current_node] & remaining_nodes):
#         remaining_links_copy = remaining_links.copy()
#         remaining_links_copy[current_node].remove(next_node) <=浅いコピーなので元のからもremoveされてる
        patterns += path_patterns_number(
            next_node,
            remaining_nodes.copy() - {next_node}
#             remaining_links_copy
        )
    
    return patterns
    
print(path_patterns_number(1, set(range(2,n+1))))