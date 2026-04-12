def func(paths, passed_node, current_node, num_node):
    global num_route
    if len(passed_node) == num_node:
            num_route += 1
            return
    for next_path in [path for path in paths if (path[0] == current_node) and (path[1] not in passed_node)]:
        new_passed_node = passed_node + [next_path[1]]
        new_paths = paths[:]
        new_paths.pop(new_paths.index([current_node, next_path[1]]))
        new_paths.pop(new_paths.index([next_path[1], current_node]))
        new_current_node = next_path[1]
        
        func(new_paths, new_passed_node, new_current_node, num_node)
    
    return num_route
    
            


num_node, num_path = map(int, input().split())
paths = [list(map(int, input().split())) for i in range(num_path)]
for path in paths[:]:
    paths.append([path[1], path[0]])
current_node = 1
passed_node = [1]
num_route = 0

try:
    func(paths, passed_node, current_node, num_node)
finally:
    print(num_route)